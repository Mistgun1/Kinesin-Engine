#include "ke_camera.h"

mat4 mat4_perspective(float fov, float aspectRatio, float near, float far){
    mat4 perspective = mat4_identity();
    
    const float DEG2RAD = PI / 180.0f;
    float tangent = tanf(fov * DEG2RAD / 2.0f);
    float top = near * tangent;
    float right = top * aspectRatio;

    perspective.m[0] = near / right;
    perspective.m[5] = near / top;
    perspective.m[10] = -(far + near) / (far - near);
    // 11 and 14 are inverted
    perspective.m[14] = -1.0f;
    perspective.m[11] = -(2.0f * far * near) / (far - near);
    perspective.m[15] = 0.0f;
    return perspective;
}

mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far){
    mat4 orthographic = mat4_identity();

    orthographic.m[0] = 2.0f / (right - left);
    orthographic.m[3] = -(right + left) / (right - left);
    orthographic.m[5] = 2.0f / (top - bottom);
    orthographic.m[7] = -(top + bottom) / (top - bottom);
    orthographic.m[10] = -2.0f / (far - near);
    orthographic.m[11] = -(far + near) / (far - near);
    orthographic.m[14] = 1.0f;
    return orthographic;
}

mat4 mat4_look_at(Camera* camera){
    vec3 direction = vec3_normalize(vec3_sub(camera->target, camera->position));
    vec3 right = vec3_normalize(vec3_cross(camera->up, direction));
   
    vec3 negative_position = vec3_negate(camera->position);
    mat4 cameraPosition = mat4_translate(&negative_position);

    mat4 cameraRotation = mat4_identity();
    cameraRotation.m[0] = right.x;
    cameraRotation.m[1] = right.y;
    cameraRotation.m[2] = right.z;
    cameraRotation.m[4] = camera->up.x;
    cameraRotation.m[5] = camera->up.y;
    cameraRotation.m[6] = camera->up.z;
    cameraRotation.m[8] = direction.x;
    cameraRotation.m[9] = direction.y;
    cameraRotation.m[10] = direction.z;

    return mat4_mul_mat4(cameraPosition, cameraRotation);
}



void ProcessMouseMovement(Camera camera, float xoffset, float yoffset, GLboolean constrainPitch )
{
 
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        camera.yaw   += xoffset;
        camera.pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

void mouse_callback(GLFWwindow* window, Camera* camera,double xposin, double yposin){
    float xpos = (float)xposin;
    float ypos = (float)yposin;
    
    bool firstmouse = true;

    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    if (firstmouse)
    {
        lastx = xpos;
        lasty = ypos;
        firstmouse = false;
    }

    float xoffset = xpos - lastx;
    float yoffset = lasty - ypos; // reversed since y-coordinates go from bottom to top

    lastx = xpos;
    lasty = ypos;

    camera.processmousemovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, Camera* camera, double xoffset, double yoffset){
    camera.ProcessMouseScroll((float)yoffset);
}
