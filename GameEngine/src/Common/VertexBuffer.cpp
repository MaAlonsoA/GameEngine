#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const std::vector<float>& data, unsigned size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(data), &data.front(), GL_STATIC_DRAW);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &ID);
}

void VertexBuffer::bind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::unBind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
