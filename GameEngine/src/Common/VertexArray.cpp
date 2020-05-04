#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::bind() const
{
	glBindVertexArray(ID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.bind();
	const auto& elemments{ layout.getElements() };
	unsigned offset{ 0 };
	for (int i{ 0 }; i < elemments.size(); i++)
	{
		const auto& element{ elemments.at(i) };
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(	i, element.amount, element.type,
								element.normalized, layout.getStride(), (const void*)offset);
		offset += element.amount * VertexBufferElements::GetSizeOfType(element.type);
	}
	
}
