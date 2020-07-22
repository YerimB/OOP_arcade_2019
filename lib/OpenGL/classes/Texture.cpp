/*
** EPITECH PROJECT, 2020
** test4
** File description:
** Texture
*/

#include "Texture.hpp"

Texture::Texture()
{
    glGenTextures(1, &this->_textureId);
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
    // Texture wrapping parameter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Texture filtering parameter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture(const std::string &path)
{
    glGenTextures(1, &this->_textureId);
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    this->loadTexture(path);
    glBindTexture(GL_TEXTURE_2D, 0);
}

const bool Texture::loadTexture(const std::string &path)
{
    if (!this->_image.loadFromFile(path)) {
        std::cerr << "[ERROR] - Texture: Couldn't load from file." << std::endl;
        return (false);
    }
    this->_width = this->_image.getSize().x;
    this->_height = this->_image.getSize().y;
    this->_image.flipVertically();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_width, this->_height, \
    0, GL_RGBA, GL_UNSIGNED_BYTE, this->_image.getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D);
    return (true);
}

void Texture::bindTexture(void) const
{
    glBindTexture(GL_TEXTURE_2D, this->_textureId);
}

Texture::~Texture()
{
    glDeleteTextures(1, &this->_textureId);
}