#pragma once
#include <type_traits>
#include <vector>

#include <glad/glad.h>

struct VertexBufferElements {
	unsigned type;
	unsigned amount;
	unsigned char normalized;

	static unsigned GetSizeOfType(unsigned type) {
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}
		return 0;
	}
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElements> elements;
	unsigned stride;
public:
	VertexBufferLayout() : stride(0) {};

	void push(float amount) {
		elements.push_back({ GL_FLOAT, static_cast<unsigned>(amount), GL_FALSE });
		stride += amount * VertexBufferElements::GetSizeOfType(GL_FLOAT);
	}

	inline const std::vector<VertexBufferElements> &getElements()const { return elements; };
	inline const unsigned getStride() const { return stride; };
};

