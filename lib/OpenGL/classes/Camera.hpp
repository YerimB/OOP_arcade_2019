/*
** EPITECH PROJECT, 2020
** test7
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Shader.hpp"

class Camera {
    public:
        Camera(const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f),
            const glm::vec3 &rotation = glm::vec3(0.0f, 0.0f, 0.0f));
        ~Camera();
    
    public:
        void updateView(void);
        const glm::mat4 &getViewMatrix(void) const;
        inline const glm::vec3 &getFront(void) const { return (this->_targetPos); };
        inline const glm::vec3 &getTop(void) const { return (this->_vectorUp); };
        inline const float getDeltaTime(void) { return (this->currentTime - this->previousTime); };

    public: /* --- TRANSFORM --- */
        enum CamEnum {
            FRONT, BACK, RIGHT, LEFT, UP, DOWN,
            ROT_X, ROT_Y,
        };
        void setPosition(const glm::vec3 &position);
        void setRotation(const glm::vec3 &rotation);
        void translateCamera(const glm::vec3 &translation);
        void rotateCamera(const glm::vec3 &rotation);
        void move(const CamEnum &direction, const float &speed);
        void rotate(const CamEnum &axis, const float &angle);

    private:
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _targetPos;
        glm::vec3 _vectorUp;
        glm::mat4 _viewMatrix;
    
    private:
        float _frontSpeed;
        float _rightSpeed;
        float _upSpeed;
        float _xRotate;
        float _yRotate;
    
    private:
        float previousTime;
        float currentTime;
};

#endif /* !CAMERA_HPP_ */