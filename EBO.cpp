//
// Created by shimo on 20/11/2024.
//
#include "EBO.h"
EBO::EBO(unsigned int * indices, GLsizeiptr size) {
    glGenBuffers(1,&ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,indices,GL_STATIC_DRAW);

}
void EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Unbinds the EBO
void EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the EBO
void EBO::Delete()
{
    glDeleteBuffers(1, &ID);
}
