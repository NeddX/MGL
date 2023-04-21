#include "Renderer.h"
#include "Geometry.h"
#include "Texture.h"
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

namespace mgl
{
	Renderer::Renderer(const int width, const int height)
		: m_Wdith(width), m_Height(height)
	{
		GL_ClearError();
		GL_Call(glViewport(0, 0, width, height));
		GL_Call(glEnable(GL_BLEND));
		GL_Call(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GL_Call(glEnable(GL_DEPTH_TEST));
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Render(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, const Shader* shader) const
	{
		vertexArray->Bind();
		indexBuffer->Bind();
		shader->Bind();
		GL_Call(glDrawElements(GL_TRIANGLES, indexBuffer->m_Indicies, GL_UNSIGNED_INT, nullptr));
	}
	
	void Renderer::Render(const VertexArray* vertexArray, const Shader* shader, uint32_t count, uint32_t offset) const
	{
		vertexArray->Bind();
		shader->Bind();
		GL_Call(glDrawArrays(GL_TRIANGLES, offset, count));
	}

	void Renderer::RenderLine(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, const Shader* shader) const
	{
		vertexArray->Bind();
		indexBuffer->Bind();
		shader->Bind();
		GL_Call(glDrawElements(GL_LINES, indexBuffer->m_Indicies, GL_UNSIGNED_INT, nullptr));
	}

	void Renderer::Clear() const
	{
		GL_Call(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void Renderer::SetClearColour(const float r, const float g, const float b, const float a) const
	{
		GL_Call(glClearColor(r, g, b, a));
	}
}