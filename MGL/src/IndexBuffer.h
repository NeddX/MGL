#ifndef MGL_INDEX_BUFFER_H
#define MGL_INDEX_BUFFER_H

#include <cstdint>

namespace mgl
{
	// Forward declerations
	class Renderer;

	class IndexBuffer
	{
		friend class Renderer;

	private:
		uint32_t m_RendererID;
		uint32_t m_Indicies;

	public:
		IndexBuffer(const uint32_t* data, const uint32_t indexCount);
		~IndexBuffer();

	public:
		inline uint32_t GetIndexCount() const { return m_Indicies; }

	public:
		void Bind() const;
		void Unbind() const;
	};
}

#endif // MGL_VERTEX_BUFFER_H