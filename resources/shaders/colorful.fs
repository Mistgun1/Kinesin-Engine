#version 420 core
out vec4 FragColor;  

in vec2 TexCoord;
in vec3 ourColor;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform vec3 lightPos;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * ourColor;
    FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0)* vec4(diffuse, 1.0);
}
