#version 330 core
out vec4 FragColor;
in vec3 color;//gets the vector of color
void main(){
    FragColor = vec4(color , 1.0f);
}