//
// Created by shimo on 20/11/2024.
//
#include "VAO.h"


// Constructor that generates a VAO ID
VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

// Links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComp, GLenum type, GLsizeiptr stride, void* offset )
{
    VBO.Bind();
    glVertexAttribPointer(layout, numComp, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

// Binds the VAO
void VAO::Bind()
{
    glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::Unbind()
{
    glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}
