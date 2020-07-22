/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Shader
*/



#ifndef SHADER_HPP_
#define SHADER_HPP_

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif

#ifdef __linux__
    #include <GL/gl.h>
    #include <GLES3/gl3.h>
#else
    #include <OpenGL/gl3.h>
#endif
// SFML includes
#include <SFML/Graphics.hpp>

// GL & SDL2 includes
//#include <GLES3/gl3.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// C++ Includes
#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
#include <vector>

class Shader {
    public:
        Shader();
        Shader(const std::string &vertFile, const std::string &fragFile);
        ~Shader();
    
    public:
        const bool setShader(const std::string &file, const GLenum &type);
        void setUniformBool(const std::string &name, const bool &value) const;
        void setUniformInt(const std::string &name, const int &value) const;
        void setUniformFloat(const std::string &name, const float &value) const;
        void setMat4(const std::string &name, const glm::mat4 &vals);

    public:
        const bool linkShaderProgram(void);
        void reset(void);
        void useProgram(void) const;
        inline GLuint getProgramId(void) const { return (this->_programID); };

    private:
        uint _vertexShaderID;
        uint _fragmentShaderID;
        uint _programID;
        char _infoLog[512];
};

#endif /* !SHADER_HPP_ */
