#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int Texture::makeTexture(unsigned char* data, unsigned int width, unsigned int height)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "ERROR: FAILED TO LOAD TEXTURE";
	}
	
	return textureID;
}

Texture::Texture(unsigned char* data, unsigned int width, unsigned int height)
{
	textureProgram = makeTexture(data, width, height);
}
