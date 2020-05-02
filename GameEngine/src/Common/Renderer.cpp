#include "Renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Shader Renderer::loadShader(const std::string& vertexPath, const std::string& fragmentPath, std::shared_ptr<std::string> geometricPath)
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

		if (!geometricPath) {
			std::string geometricCode;
			std::ifstream gShaderFile(*geometricPath);

			std::stringstream gShaderSS;
			gShaderSS << gShaderFile.rdbuf();
			gShaderFile.close();

			geometricCode = gShaderSS.str();

			//return shader with geometric
			Shader shader(vertexCode, fragmentCode, std::make_shared<std::string>(geometricCode));
			return shader;
		}
		else {
			//return shader without geometric
			Shader shader(vertexCode, fragmentCode, nullptr);
			return shader;
		}

	} catch (const std::string msg)
	{
		std::cout << "ERROR:FAILED TO READ SHADER FILES\n";
	}
};

Texture Renderer::loadTexture(const std::string& texturePath, bool alpha)
{
	int width;
	int height;
	int nrChannels;
	const char* src = texturePath.c_str();

	unsigned char* textureData = stbi_load(src, &width, &height, &nrChannels, 0);
	Texture texture(textureData, width, height);
	stbi_image_free(textureData);
}

std::shared_ptr<Shader> Renderer::getShader()
{
	return shader;
}

std::shared_ptr<Texture> Renderer::getTexture()
{
	return texture;
}

void Renderer::initRenderer()
{

}





