#include "texture.h"

unsigned Texture::makeTexture(unsigned char* data, unsigned width, unsigned height)
{
	unsigned textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}

Texture::Texture(unsigned char* data, unsigned width, unsigned height) :
	ID {makeTexture(data, width, height)}
{

}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

unsigned Texture::getID()
{
	return ID;
}

void Texture::bind() const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
