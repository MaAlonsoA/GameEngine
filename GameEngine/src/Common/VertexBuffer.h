#pragma once

#include <vector>

#include <glad/glad.h>

class VertexBuffer
{
private: 
	unsigned ID;
public:
	VertexBuffer(const std::vector<float>& data, unsigned size);
	~VertexBuffer();

	void bind()const;
	void unBind()const;
};

