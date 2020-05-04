#pragma once

#include <string>
#include <array>

#include <glad/glad.h>

class Shader
{
private:
	unsigned ID;
	unsigned makeShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned compileShader(const std::string& source, unsigned type);
	void checkCompileError(unsigned shader, unsigned type) const;
	unsigned getUniformLocation(const std::string& name);

	
public:
	Shader(const std::string& vertexCode, const std::string& fragmentCode);
	~Shader();
	void use() const;
	void unBind() const;
	unsigned getID() const;

	//Uniforms
	void setUniform1i(const std::string& uniformName, int value);
	void setUniform1f(const std::string& uniformName, float value);
	void setUniform2f(const std::string& uniformName, std::array<float, 2> values);
	void setUniform3f(const std::string& uniformName, std::array<float, 3> values);
	void setUniform4f(const std::string& uniformName, std::array<float, 4> values);
};

