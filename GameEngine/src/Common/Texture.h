#pragma once

#include <memory>
#include <iostream>

#include <glad/glad.h>

class Texture 
{
private: 
	unsigned int textureProgram;
	unsigned int makeTexture(unsigned char* data, unsigned int width, unsigned int height);

public:
	Texture(unsigned char* data, unsigned int width, unsigned int height);
	unsigned int getTexture() const;

};

