//
// Created by shimo on 20/11/2024.
//

#include "utils.h"

#include <fstream>

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}
Shader::Shader(const char* vertexFile, const char* fragmentFile) {

    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    // Convert the shader source strings into character arrays
    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();



    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL); //shader source
    glCompileShader(vertexShader);//compile the results


    //create a fragment shader and passing the source
    unsigned int fragmentShader =glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentSource,NULL);
    glCompileShader(fragmentShader);



    // Create Shader Program Object and get its reference
    ID = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(ID);

    // Delete the now useless Vertex and Fragment Shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


}
void Shader::Activate() {
    glUseProgram(ID);
}
void Shader::Delete() {
    glDeleteProgram(ID);
}
void Shader::drawTriangle(GLFWwindow *window, const unsigned int V_ID) {
    // Specify the color of the background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // Clean the back buffer and assign the new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // Tell OpenGL which Shader Program we want to use
    this->Activate();
    // Bind the VAO so OpenGL knows to use it
    //VAO1.Bind();
    glBindVertexArray(V_ID);
    // Draw primitives, number of indices, datatype of indices, index of indices
    //glDrawArrays(GL_TRIANGLES,0,9);
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);
}



