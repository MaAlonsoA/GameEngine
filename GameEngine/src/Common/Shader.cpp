#include "Shader.h"

#include <iostream>

unsigned Shader::makeShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned shaderProgram{ glCreateProgram() };
	unsigned vs{ compileShader(vertexShader, GL_VERTEX_SHADER) };
	unsigned fs{ compileShader(fragmentShader, GL_FRAGMENT_SHADER) };

	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

	glLinkProgram(shaderProgram);
	return shaderProgram;
}

unsigned Shader::compileShader(const std::string& source, unsigned type)
{
	unsigned shaderProgram{ glCreateShader(type) };
	const char* src{ source.c_str() }; //c_str to convert std::string into C_Style pointer char;

	glShaderSource(shaderProgram, 1, &src, nullptr);
	glCompileShader(shaderProgram);

	checkCompileError(shaderProgram, type);

	return shaderProgram;
}


void Shader::checkCompileError(unsigned  shader, unsigned  type) const
{
	int success;
	char infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
	}
}


unsigned Shader::getUniformLocation(const std::string& name)
{
	int location{ glGetUniformLocation(ID, name.c_str()) };
	if (location == -1) 
		std::cout << "WARNING: uniform " << name << " not found!\n";
	
	return location;
}


Shader::Shader(const std::string& vertexCode, const std::string& fragmentCode) :
	ID{ makeShader(vertexCode,fragmentCode) }
{

}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::unBind() const
{
	glUseProgram(0);
}

unsigned Shader::getID() const
{
	return ID;
}

void Shader::setUniform1i(const std::string& uniformName, int value)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniform1f(location, value);
}

void Shader::setUniform1f(const std::string& uniformName, float value)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniform1f(location, value);
}

void Shader::setUniform2f(const std::string& uniformName, const glm::vec2& values)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniform2f(location, values.x, values.y);
}

void Shader::setUniform3f(const std::string& uniformName, const glm::vec3& values)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniform3f(location, values.x, values.y, values.z);
}

void Shader::setUniform4f(const std::string& uniformName, const glm::vec4& values)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniform4f(location, values.x, values.y, values.z, values.w);
}

void Shader::setUniformMatrix4(const std::string& uniformName, const glm::mat4& values)
{
	unsigned location{ getUniformLocation(uniformName) };
	glUniformMatrix4fv(location, 1, false, glm::value_ptr(values));
}
