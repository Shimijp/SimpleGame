//
// Created by shimo on 20/11/2024.
//

#ifndef VAO_H
#define VAO_H
#include <glad/glad.h>
class EBO {
public:
    unsigned int ID;
    EBO(unsigned int * indices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();
};

#endif //VAO_H
