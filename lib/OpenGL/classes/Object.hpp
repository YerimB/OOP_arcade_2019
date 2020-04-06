/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif


#include "Texture.hpp"
#include "Camera.hpp"

class Object {
    public:
        Object(const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &rotation = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &scalation = glm::vec3(1.0f, 1.0f, 1.0f));
        ~Object();
        void setVBO(const uint &vbo, const uint &verticeNb);
        void setEBO(const uint &ebo, const uint &indiceNb);
        void setVAO(const uint &vao);
        inline uint getVBO(void) const { return (this->_VBO); };
        inline uint getEBO(void) const { return (this->_EBO); };
        inline uint getVAO(void) const { return (this->_VAO); };
        inline const Shader &getShader(void) { return (this->_shader); };

    public: /* --- DRAWING --- */
        void setVertices(const float *array, uint arraySize, GLenum drawType);
        void setVertices(const std::vector<float> &array, GLenum drawType);
        void setIndices(const uint *array, uint arraySize, GLenum drawType);
        void setIndices(const std::vector<uint> &array, GLenum drawType);
        void setShader(const Shader &shader, const glm::mat4 &projectionMatrix);
        void setTexture(std::shared_ptr<Texture> texture);
        void draw(GLenum drawMode, const glm::mat4 &projectionMatrix, const Camera &c);

    public: /* --- TRANSFORM --- */
        enum CamEnum {
            POS_X, POS_Y, POS_Z,
            ROT_X, ROT_Y, ROT_Z,
            SCALE_X, SCALE_Y, SCALE_Z
        };
        void setViewMatrix(const glm::mat4 &viewMatrix);
        void setTranslate(void);
        void setScale(void);
        void setRotate(void);
        void setPosition(const glm::vec3 &position);
        void setScalation(const glm::vec3 &scalation);
        void setRotation(const glm::vec3 &rotation);
        void move(const CamEnum &axe, const float &distance);
        void scale(const CamEnum &axe, const float &strength);
        void rotate(const CamEnum &axe, const float &degrees);
        void actualizeTransform(const glm::mat4 &projectionMatrix);

    private:
        uint _VAO;
        uint _VBO;
        uint _EBO;
        int _verticeNumber = (-1);
        int _indiceNumber = (-1);

    private:
        Shader _shader;
        std::shared_ptr<Texture> _texture;
    
    private:
        // Model
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scalation;
        glm::mat4 _posMat;
        glm::mat4 _rotMat;
        glm::mat4 _scalMat;
        glm::mat4 _modelMat;
        // View
        glm::mat4 _viewMat;
};

#endif /* !OBJECT_HPP_ */
