#pragma once

#include <string>
#include <memory>
#include <iostream>

#include <glad/glad.h>


class Shader
{
private: 
	unsigned int shaderProgram;
	unsigned int makeShader(	const std::string& vertexShader, 
								const std::string& fragmentShader, 
								std::shared_ptr<std::string> geometricPath
							);
	unsigned int compileShader(unsigned int type, const std::string& source);
	void checkCompileErros(unsigned int shader, unsigned int type);
public:
	Shader( const std::string& vertexCode, 
			const std::string& fragmentCode, 
			std::shared_ptr<std::string> geometricCode
	);
	~Shader();
	void use();
};

