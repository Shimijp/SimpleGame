//
// Created by shimo on 20/11/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define HEIGHT 800
#define WIEDTH 800

std::string get_file_contents(const char * filename);

class Shader {

public:
    unsigned int ID;
    Shader(const char* vertexFile, const char* fragmentFile);
    void Activate();
    void Delete();
    void drawTriangle(GLFWwindow * window,unsigned int V_ID);


};


#endif //UTILS_H
