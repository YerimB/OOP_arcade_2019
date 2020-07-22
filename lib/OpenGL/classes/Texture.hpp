/*
** EPITECH PROJECT, 2020
** test4
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "Shader.hpp"

class Texture {
    public:
        Texture();
        Texture(const std::string &path);
        ~Texture();

    public:
        inline const uint &getTextureId(void) const { return (this->_textureId); };
        const bool loadTexture(const std::string &path);
        void bindTexture(void) const;

    private:
        sf::Image _image;
        uint _textureId;
        int _width;
        int _height;
};

#endif /* !TEXTURE_HPP_ */