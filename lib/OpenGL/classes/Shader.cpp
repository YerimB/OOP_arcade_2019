/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Shader
*/

#include "Shader.hpp"

Shader::Shader()
{
    this->_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    this->_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    this->_programID = glCreateProgram();
}

Shader::Shader(const std::string &vertFilePath, const std::string &fragFilePath)
{
    this->_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    this->_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    this->_programID = glCreateProgram();

    if (!setShader(vertFilePath, GL_VERTEX_SHADER) || \
    !setShader(fragFilePath, GL_FRAGMENT_SHADER) || !linkShaderProgram())
        std::exit(84);
}

void Shader::reset(void)
{
    glDeleteShader(this->_vertexShaderID);
    glDeleteShader(this->_fragmentShaderID);
    glDeleteProgram(this->_programID);
    this->_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    this->_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    this->_programID = glCreateProgram();
}

const bool Shader::setShader(const std::string &file, const GLenum &type)
{
    uint shaderId = (type == GL_VERTEX_SHADER) ? this->_vertexShaderID : this->_fragmentShaderID;
    std::string content;
    std::ifstream stream(file);
    char *tto = nullptr;
    int success;

    if (stream.bad() || stream.fail()) {
        std::cerr << "[ERROR] - Shader: Couldn't open file." << std::endl;
        stream.close();
        return (false);
    }
    for (std::string tmp; std::getline(stream, tmp);)
        content += (tmp + "\n");
    stream.close();
    glShaderSource(shaderId, 1, &(tto = (char *)content.c_str()), NULL);
    glCompileShader(shaderId);
    // Check shader compilation status
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderId, 512, NULL, this->_infoLog);
        std::cerr << "[ERROR] - SHADER::" << shaderId \
        << "::COMPILATION_FAILED\n" << this->_infoLog << std::endl;
        return (false);
    }
    return (true);
}

const bool Shader::linkShaderProgram(void)
{
    int success;

    glAttachShader(this->_programID, this->_vertexShaderID);
    glAttachShader(this->_programID, this->_fragmentShaderID);
    glLinkProgram(this->_programID);

    // Check program link status
    glGetProgramiv(this->_programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->_programID, 512, NULL, this->_infoLog);
        std::cerr << "[ERROR] - PROGRAM::" << this->_programID \
        << "::LINKING_FAILED\n" << this->_infoLog << std::endl;
        return (false);
    }
    glDeleteShader(this->_vertexShaderID);
    glDeleteShader(this->_fragmentShaderID);
    return (true);
}

void Shader::setUniformBool(const std::string &name, const bool &value) const
{
    int uniformLocation = glGetUniformLocation(this->_programID, name.c_str());

    if (uniformLocation == (-1)) {
        std::cerr << "[ERROR] - Couldn't find uniform variable: " << name << std::endl;
        std::exit(84);
    }
    glUniform1i((uint)uniformLocation, value);
}

void Shader::setUniformInt(const std::string &name, const int &value) const
{
    int uniformLocation = glGetUniformLocation(this->_programID, name.c_str());

    if (uniformLocation == (-1)) {
        std::cerr << "[ERROR] - Couldn't find uniform variable: " << name << std::endl;
        std::exit(84);
    }
    glUniform1i((uint)uniformLocation, value);
}

void Shader::setUniformFloat(const std::string &name, const float &value) const
{
    int uniformLocation = glGetUniformLocation(this->_programID, name.c_str());

    if (uniformLocation == (-1)) {
        std::cerr << "[ERROR] - Couldn't find uniform variable: " << name << std::endl;
        std::exit(84);
    }
    glUniform1f(static_cast<uint>(uniformLocation), value);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &vals)
{
    int matrixLoc = glGetUniformLocation(this->_programID, name.c_str());

    if (matrixLoc == (-1)) {
        std::cerr << "[ERROR] - Couldn't find uniform mat4: " << name << std::endl;
        std::exit(84);
    }
    glUniformMatrix4fv(static_cast<uint>(matrixLoc), 1, GL_FALSE, glm::value_ptr(vals));
}

void Shader::useProgram(void) const
{
    glUseProgram(this->_programID);
}

Shader::~Shader()
{
    glDeleteShader(this->_vertexShaderID);
    glDeleteShader(this->_fragmentShaderID);
    glDeleteProgram(this->_programID);
}
