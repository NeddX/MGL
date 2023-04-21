#include "IndexBuffer.h"
#include "Renderer.h"

namespace mgl
{
	IndexBuffer::IndexBuffer(const uint32_t* data, const uint32_t indexCount)
		: m_Indicies(indexCount)
	{
		GL_Call(glGenBuffers(1, &m_RendererID));
		GL_Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
		GL_Call(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint32_t), data, GL_STATIC_DRAW));
	}

	IndexBuffer::~IndexBuffer()
	{
		GL_Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
		GL_Call(glDeleteBuffers(1, &m_RendererID));
	}

	void IndexBuffer::Bind() const
	{
		GL_Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	}

	void IndexBuffer::Unbind() const
	{
		GL_Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}