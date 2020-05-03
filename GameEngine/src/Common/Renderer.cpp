#include "Renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int Renderer::loadShader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	
	try
	{
		std::ifstream vShaderFile(vertexPath);
		std::ifstream fShaderFile(fragmentPath);

		std::stringstream vShaderSS;
		vShaderSS << vShaderFile.rdbuf();
		std::stringstream fShaderSS;
		fShaderSS << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderSS.str();
		fragmentCode = fShaderSS.str();

		Shader shader(vertexCode, fragmentCode);
		return shader.getShader();

	} catch (const std::string msg)
	{
		std::cout << "ERROR:FAILED TO READ SHADER FILES\n";
	}
};

unsigned int Renderer::loadTexture(const std::string& texturePath, bool alpha)
{
	int width{512};
	int height{512};
	int nrChannels;
	const char* src = texturePath.c_str();

	unsigned char* textureData = stbi_load(src, &width, &height, &nrChannels, 0);
	Texture texture(textureData, width, height);
	stbi_image_free(textureData);
	return texture.getTexture();
}



void Renderer::initRenderer()
{

	//Create VAO & VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//Bind VBO & VAO
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(	GL_ARRAY_BUFFER,
					vertexSize * sizeof(vertices),
					&vertices.front(),
					GL_STATIC_DRAW
				);
	
	//Enable & Attributes
	glVertexAttribPointer(	0, 
							vertexSize,
							GL_FLOAT,
							GL_FALSE,
							vertexSize * sizeof(float),
							(void*)0
	);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
 	glBindVertexArray(0);

}


void Renderer::update()
{
	glUseProgram(shaderProgram);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertexSize);
	glBindVertexArray(0);
}

Renderer::Renderer(	const std::string& vertexPath, const std::string& fragmentPat, const std::vector<float>& vertices, unsigned short vertexSize,
					const std::string& texturePath, bool alpha) :
	vertices{ vertices },
	vertexSize{ vertexSize },
	shaderProgram{ loadShader(vertexPath, fragmentPat) },
	textureProgram{ loadTexture(texturePath, alpha) }
{
	

}



