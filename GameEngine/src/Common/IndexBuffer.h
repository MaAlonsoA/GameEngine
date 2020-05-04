#pragma once

#include <vector>

#include <glad/glad.h>

class IndexBuffer
{
private:
	unsigned ID;
	unsigned amount;
public:
	IndexBuffer(const std::vector<unsigned>& data, unsigned amount);
	~IndexBuffer();

	void bind()const;
	void unBind()const;
	unsigned getAmount()const;
};
