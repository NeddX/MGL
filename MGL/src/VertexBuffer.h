#ifndef MGL_VERTEX_BUFFER_H
#define MGL_VERTEX_BUFFER_H

#include <cstdint>
#include <iostream>

#include "Renderer.h"

namespace mgl
{
	class VertexBuffer
	{
	private:
		uint32_t m_RendererID;
		uint32_t m_VertexCount;

	public:
		inline uint32_t GetVertexCount() const { return m_VertexCount; }

	public:
		VertexBuffer();
		~VertexBuffer();

	public:
		void Bind() const;
		void Unbind() const;
		
	public:
		template<typename T>
		void SetBuffer(const void* data, uint32_t size)
		{
			GL_Call(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
			GL_Call(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
			m_VertexCount = size / sizeof(T);
		}
	};
}

#endif // MGL_VERTEX_BUFFER_H