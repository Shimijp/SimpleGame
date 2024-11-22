

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <cmath>
#include <complex>

#include"utils.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include "mandelbrotCalc.h"

void updateScreenLoop(GLFWwindow *window,unsigned int shaderProgram ,unsigned int VAO);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window );
const char * fragLoc = "/home/shimon/SimpleGame/SimpleGame/defult.frag";
const char * vertLoc = "/home/shimon/SimpleGame/SimpleGame/defult.vert";
int main() {



    glfwInit();//initialize glfw

    //set the version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create a pointer to the GLFW window struct with the with and height and title spesified
    GLFWwindow * window = glfwCreateWindow(WIEDTH, HEIGHT, "Simple Game", NULL, NULL);
    //check if the window created
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Vertices coordinates
    GLfloat vertices[3000] =
    { //               COORDINATES                  /     COLORS           //
        -0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
         0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
         0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
        -0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
         0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
         0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
    };

    //the index array to use
    unsigned int indices[] ={
        0,3,5,//lower left triangle
        3,2,4,//lower right triangle
        5, 4 ,1//upper triangle


    };

    glfwMakeContextCurrent(window);
    //make glad load the opengl files
    gladLoadGL();

    glClearColor(-0.07f,0.13f,0.117f,1.0f); //setting to color to gray
    glClear(GL_COLOR_BUFFER_BIT); //clears the screen and assign the color to it
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);//updates the screen size and color
    //creates shader and return int as reference value

    Shader shaderProgram(vertLoc,fragLoc);

    unsigned int ScaleID = glGetUniformLocation(shaderProgram.ID,"scale");//find the scalse id from uniform
    VAO VAO1;

    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO to VAO
    VAO1.LinkAttrib(VBO1, 0, 3 ,GL_FLOAT,6* sizeof(float),(void*)0);
    //for the color part of the coordinats
   VAO1.LinkAttrib(VBO1,1,3,GL_FLOAT, 6*sizeof(float),(void*)(3*sizeof(float)));
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
   EBO1.Unbind();
   while (!glfwWindowShouldClose(window))
    {
       // Specify the color of the background
       glClearColor(-0.07f,0.13f,0.117f,1.0f);
       // Clean the back buffer and assign the new color to it
       glClear(GL_COLOR_BUFFER_BIT);
       // Tell OpenGL which Shader Program we want to use
       shaderProgram.Activate();






       // Bind the VAO so OpenGL knows to use it
       VAO1.Bind();
       // Draw primitives, number of indices, datatype of indices, index of indices
       glDrawElements(GL_LINE_LOOP, 9, GL_UNSIGNED_INT, 0);


       // Swap the back buffer with the front buffer
       glfwSwapBuffers(window);
       // Take care of all GLFW events
       glfwPollEvents();
    }

    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

}
//process user input
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


//to adjust the window according to user use