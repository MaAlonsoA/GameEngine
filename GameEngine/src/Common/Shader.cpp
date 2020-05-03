#include "Shader.h"
#include <iostream>

unsigned int Shader::makeShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int shaderProgram{ glCreateProgram() };
	unsigned int vs{ compileShader(GL_VERTEX_SHADER, vertexShader) };
	unsigned int fs{ compileShader(GL_FRAGMENT_SHADER, fragmentShader) };
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);
	glLinkProgram(shaderProgram);
	return shaderProgram;
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
{
	unsigned int shaderID{ glCreateShader(type) };
	const char* src{ source.c_str() }; // c_str() to convert std::string into C-Style pointer string;
	glShaderSource(shaderID, 1, &src, nullptr);
	glCompileShader(shaderID);
	checkCompileErros(shaderID, type);


	return shaderID;
}

//function from learnopenGL.com
void Shader::checkCompileErros(unsigned int shader, unsigned int type)
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

Shader::Shader(const std::string& vertexCode, const std::string& fragmentCode) :
	shaderProgram{ makeShader(vertexCode, fragmentCode) }
{

}

Shader::~Shader()
{

}

unsigned int Shader::getShader() const
{
	return shaderProgram;
}

