/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Object
*/

#include "Object.hpp"

/* -------------- INITIALIZATION -------------- */

Object::Object(const glm::vec3 &position, \
const glm::vec3 &rotation, const glm::vec3 &scalation) :
_position(position), _scalation(scalation), _viewMat(1.0f), _modelMat(1.0f)
{
    glGenVertexArrays(1, &(this->_VAO));

    glGenBuffers(1, &(this->_VBO));
    glGenBuffers(1, &(this->_EBO));
    this->setRotation(rotation); // Radians conversion in the function
}

/* -------------- SETTERS -------------- */

void Object::setVertices(const float *data, uint arraySize, GLenum drawType)
{
    this->_verticeNumber = arraySize;

    glBindVertexArray(this->_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO);
    glBufferData(GL_ARRAY_BUFFER, arraySize * sizeof(float), data, drawType);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::setVertices(const std::vector<float> &data, GLenum drawType)
{
    this->_verticeNumber = data.size();

    glBindVertexArray(this->_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->_VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), drawType);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::setIndices(const uint *data, uint arraySize, GLenum drawType)
{
    this->_indiceNumber = arraySize;

    glBindVertexArray(this->_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, arraySize * sizeof(uint), data, drawType);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Object::setIndices(const std::vector<uint> &array, GLenum drawType)
{
    this->_indiceNumber = array.size();

    glBindVertexArray(this->_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, array.size() * sizeof(uint), array.data(), drawType);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Object::setVBO(const uint &VBO, const uint &verticeNumber)
{
    this->_VBO = VBO;
    this->_verticeNumber = verticeNumber;
}

void Object::setEBO(const uint &EBO, const uint &indiceNumber)
{
    this->_EBO = EBO;
    this->_indiceNumber = indiceNumber;
}

void Object::setVAO(const uint &VAO)
{
    this->_VAO = VAO;
}

void Object::setShader(const Shader &shader, const glm::mat4 &projectionMatrix)
{
    this->_shader = shader;
    this->_shader.setMat4("projection", projectionMatrix);
}

void Object::setTexture(std::shared_ptr<Texture> texture)
{
    this->_texture = texture;
}

void Object::setViewMatrix(const glm::mat4 &viewMatrix)
{
    this->_viewMat = viewMatrix;
}

void Object::setPosition(const glm::vec3 &position)
{
    this->_position.x = position.x;
    this->_position.y = position.y;
    this->_position.z = position.z;
}

void Object::setRotation(const glm::vec3 &rotation)
{
    this->_rotation.x = glm::radians(rotation.x);
    this->_rotation.y = glm::radians(rotation.y);
    this->_rotation.z = glm::radians(rotation.z);
}

void Object::setScalation(const glm::vec3 &scalation)
{
    this->_scalation.x = scalation.x;
    this->_scalation.y = scalation.y;
    this->_scalation.z = scalation.z;
}

void Object::setTranslate(void)
{
    this->_modelMat = glm::translate(glm::mat4(1.0f), this->_position);
}

void Object::setScale(void)
{
    this->_modelMat = glm::scale(this->_modelMat, this->_scalation);
}

void Object::setRotate(void)
{
    this->_modelMat = glm::rotate(this->_modelMat, this->_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    this->_modelMat = glm::rotate(this->_modelMat, this->_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    this->_modelMat = glm::rotate(this->_modelMat, this->_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
}

/* -------------- DURING PROGRAM -------------- */

void Object::move(const CamEnum &axe, const float &dist)
{
    switch (axe) {
        case POS_X: this->_position.x += dist; break;
        case POS_Y: this->_position.y += dist; break;
        case POS_Z: this->_position.z += dist; break;
        default: break;
    }
}

void Object::rotate(const CamEnum &axe, const float &deg)
{
    switch (axe) {
        case ROT_X: this->_rotation.x += glm::radians(deg); break;
        case ROT_Y: this->_rotation.y += glm::radians(deg); break;
        case ROT_Z: this->_rotation.z += glm::radians(deg); break;
        default: break;
    }
}

void Object::scale(const CamEnum &axe, const float &strength)
{
    switch (axe) {
        case SCALE_X: this->_scalation.x += strength; break;
        case SCALE_Y: this->_scalation.y += strength; break;
        case SCALE_Z: this->_scalation.z += strength; break;
        default: break;
    }
}

void Object::actualizeTransform(const glm::mat4 &projectionMatrix)
{
    this->setTranslate();
    this->setScale();
    this->setRotate();
    this->_shader.setMat4("view", this->_viewMat);
    this->_shader.setMat4("model", this->_modelMat);
    this->_shader.setMat4("projection", projectionMatrix);
}

void Object::draw(GLenum drawMode, const glm::mat4 &projM, const Camera &c)
{
    // Set Transform and perspective
    this->actualizeTransform(projM);
    this->setViewMatrix(c.getViewMatrix());

    // Bind shader and Texture
    this->_shader.useProgram();
    glActiveTexture(GL_TEXTURE0);
    this->_texture->bindTexture();

    // Bind vertex array
    glBindVertexArray(this->_VAO);
    if (this->_indiceNumber != (-1))
        glDrawElements(drawMode, this->_indiceNumber, GL_UNSIGNED_INT, 0);
    else if (this->_verticeNumber != (-1))
        glDrawArrays(drawMode, 0, this->_verticeNumber);
    else
        std::cerr << "Can't draw this object." << std::endl;
    glBindVertexArray(0);
}

Object::~Object()
{
    glDeleteBuffers(1, &(this->_VBO));
    glDeleteBuffers(1, &(this->_EBO));
    glDeleteVertexArrays(1, &(this->_VAO));
}