#pragma once

#include <glad/glad.h>

class Texture
{
private:
	unsigned ID;
	unsigned makeTexture(unsigned char* data, unsigned width, unsigned height);

public:
	Texture(unsigned char* data, unsigned width, unsigned height);
	~Texture();
	unsigned getID();
	void bind() const;
	void unBind();
};


