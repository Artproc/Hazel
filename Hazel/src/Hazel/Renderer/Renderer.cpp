#include "hzpch.h"
#include "Renderer.h"
#include "RenderCommand.h"

namespace Hazel {

	Renderer* Renderer::s_Instance = new Renderer();

	void Renderer::Init()
	{

	}

	void Renderer::Clear()
	{
		
	}

	void Renderer::Clear(float r, float g, float b, float a /*= 1.0f*/)
	{
		HZ_RENDER_4(r, g, b, a) {
			RendererAPI::Clear(r, g, b, a);
		}
	}

	void Renderer::ClearMagenta()
	{
		Clear(1, 0, 1);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
		
	}

	void Renderer::DrawIndexed(unsigned int count)
	{
		HZ_RENDER_1(count, {
			RendererAPI::DrawIndexed(count);
			});
	}

	void Renderer::WaitAndRender()
	{
		s_Instance->m_CommandQueue.Execute();
	}

	

}