#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const std::vector<unsigned>& data, unsigned amount) :
	amount {amount}
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, amount * sizeof(unsigned), &data.front(), GL_STATIC_DRAW);
}


IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &ID);
}

void IndexBuffer::bind()const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IndexBuffer::unBind()const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned IndexBuffer::getAmount() const
{
	return amount;
}
