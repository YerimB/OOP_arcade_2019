/*
** EPITECH PROJECT, 2020
** test7
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(const glm::vec3 &position, const glm::vec3 &rotation) :
_position(position), _rotation(rotation),
_targetPos(0.0f, 0.0f, 1.0f), _vectorUp(0.0f, 1.0f, 0.0f)
{
    this->previousTime = float(SDL_GetTicks()) / 1000;
    this->_rightSpeed = 0.0f;
    this->_frontSpeed = 0.0f;
    this->_upSpeed = 0.0f;
    this->_xRotate = 0.0f;
    this->_yRotate = 0.0f;
    this->updateView();
}

void Camera::setPosition(const glm::vec3 &position)
{
    this->_position.x = position.x;
    this->_position.y = position.y;
    this->_position.z = position.z;
}

void Camera::setRotation(const glm::vec3 &rotation)
{
    this->_rotation.x = rotation.x;
    this->_rotation.y = rotation.y;
    this->_rotation.z = rotation.z;
}

void Camera::translateCamera(const glm::vec3 &translation)
{
    this->_position.x += translation.x;
    this->_position.y += translation.y;
    this->_position.z += translation.z;
}

void Camera::rotateCamera(const glm::vec3 &rotation)
{
    this->_rotation.x += rotation.x;
    this->_rotation.y += rotation.y;
    this->_rotation.x -= ((this->_rotation.x > 360.0) ? 360.0 : 0.0);
    this->_rotation.x += ((this->_rotation.x < 0.0) ? 360.0 : 0.0);
    this->_rotation.y -= ((this->_rotation.y > 360.0) ? 360.0 : 0.0);
    this->_rotation.y += ((this->_rotation.y < 0.0) ? 360.0 : 0.0);
    this->_targetPos = glm::normalize(glm::vec3(
        cos(glm::radians(this->_rotation.x)) * cos(glm::radians(this->_rotation.y)),
        sin(glm::radians(this->_rotation.y)),
        sin(glm::radians(this->_rotation.x)) * cos(glm::radians(this->_rotation.y))
    ));
}

void Camera::updateView(void)
{
    this->currentTime = float(SDL_GetTicks()) / 1000;
    this->translateCamera(_frontSpeed * this->getFront() * getDeltaTime());
    this->translateCamera(_upSpeed * this->getTop() * getDeltaTime());
    this->translateCamera(_rightSpeed * glm::cross(this->getFront(), this->getTop()) * getDeltaTime());
    this->rotateCamera(glm::vec3(_xRotate * getDeltaTime(), _yRotate * getDeltaTime(), 0.0f));
    this->_viewMatrix = glm::lookAt(_position, _position + _targetPos, _vectorUp);
    this->previousTime = this->currentTime;
}

const glm::mat4 &Camera::getViewMatrix(void) const
{
    return (this->_viewMatrix);
}

void Camera::move(const CamEnum &direction, const float &speed)
{
    switch (direction) {
        case FRONT: this->_frontSpeed = speed; break;
        case BACK: this->_frontSpeed = -speed; break;
        case RIGHT: this->_rightSpeed = speed; break;
        case LEFT: this->_rightSpeed = -speed; break;
        case UP: this->_upSpeed = speed; break;
        case DOWN: this->_upSpeed = -speed; break;
        default: break;
    }
}

void Camera::rotate(const CamEnum &axis, const float &angle)
{
    switch (axis) {
        case ROT_X: this->_xRotate = angle; break;
        case ROT_Y: this->_yRotate = angle; break;
        default: break;
    }
}

Camera::~Camera() {}