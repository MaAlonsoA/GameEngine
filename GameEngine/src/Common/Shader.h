#pragma once

#include <string>
#include <array>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


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
	void setUniform2f(const std::string& uniformName, const glm::vec2& values);
	void setUniform3f(const std::string& uniformName, const glm::vec3& values);
	void setUniform4f(const std::string& uniformName, const glm::vec4& values);
	void setUniformMatrix4(const std::string& uniformName, const glm::mat4& values);
};

