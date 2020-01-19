

#ifndef MESH_H
#define MESH_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ogl_shader_API/shader_program_controller.h"
#include "ogl_shader_API/data_buffer.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

struct Vertex {
    // position
    glm::vec3 Position;
};

class Mesh {
public:
    /*  Mesh Data  */
    vector<Vertex> vertices;
    vector<unsigned int> indices;


    /*  Functions  */
    // constructor
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, GLuint shaderProgram)
    {
        this->vertices = vertices;
        this->indices = indices;

        // now that we have all the required data, set the vertex buffers and its attribute pointers.
        setupMesh(shaderProgram);
    }

    // render the mesh
    void Draw(const ShaderProgramController& program)
    {
        // draw mesh
        vertexBufferObject->bindVertexArray(vertexBufferObject->getVertexArrayObject());
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        explodeBufferObject->bindVertexArray(0);
    }

private:
    /*  Render data  */
    DataBuffer* vertexBufferObject;
    DataBuffer* explodeBufferObject;


    /*  Functions    */
    // initializes all the buffer objects/arrays
    void setupMesh(GLuint shaderProgram)
    {
        // create buffers/arrays
        vertexBufferObject = new DataBuffer(1, shaderProgram);
        explodeBufferObject = new DataBuffer(1, shaderProgram);


        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        vertexBufferObject->generate(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0]);
        explodeBufferObject->generate(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], false);
        explodeBufferObject->setVertexArrayObject(vertexBufferObject->getVertexArrayObject());


        // set the vertex attribute pointers
        // vertex Positions
        //GLuint posAttrib, GLuint vertexSize, bool normalized, size_t vertexPadding, void* offset

        vertexBufferObject->enableAttributeArrayByPosition(0, 3, false, sizeof(Vertex), (void*)0 );

        vertexBufferObject->bindVertexArray(0);
    }
};
#endif

