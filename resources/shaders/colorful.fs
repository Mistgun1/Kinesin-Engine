#version 420 core
sttruct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};
uniform Material material;

out vec4 FragColor;  

in vec2 TexCoord;
in vec3 ourColor;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vec3 ambient = material.ambient * ourColor;
    
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = (diff * material.diffuse) * ourColor;
    
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = (material.specular * spec) * ourColor;
   
    vec3 result = (diffuse + specular + ambient) * vec3(texture(ourTexture, TexCoord));
    FragColor = vec4(result, 1.0);
}
