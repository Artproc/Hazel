#include "Hazel.h"

#include "Hazel/ImGui/ImGuiLayer.h"

static void ImGuiShowHelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsAnyItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

class EditorLayer : public Hazel::Layer
{
public:
	EditorLayer()
		:m_ClearColor{ 0.2f, 0.3f, 0.8f, 1.0f }
	{
		
	}

	virtual ~EditorLayer()
	{
	}

	virtual void OnAttach() override
	{
		static float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		static unsigned int indices[] = {
			0, 1, 2
		};
		m_VB = std::unique_ptr<Hazel::VertexBuffer>(Hazel::VertexBuffer::Create());
		m_VB->SetData(vertices, sizeof(vertices));
		m_IB = std::unique_ptr<Hazel::IndexBuffer>(Hazel::IndexBuffer::Create());
		m_IB->SetData(indices, sizeof(indices));
	}

	virtual void OnDetach() override
	{
	}

	virtual void OnUpdate() override
	{
		
		using namespace Hazel;
		Renderer::Clear(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
		m_VB->Bind();
		m_IB->Bind();
		Renderer::DrawIndexed(3);

	}

	virtual void OnImGuiRender()override
	{
		
// 		static bool show_demo_window = true;
// 		if (show_demo_window)
//  			ImGui::ShowDemoWindow(&show_demo_window);

		ImGui::Begin("GameLayer");
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
		ImGui::End();


	}

	virtual void OnEvent(Hazel::Event& event) override
	{
	}
private:
	std::unique_ptr<Hazel::VertexBuffer> m_VB;
	std::unique_ptr<Hazel::IndexBuffer> m_IB;
	float m_ClearColor[4];
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		HZ_TRACE("Hello!");
	}

	virtual void OnInit() override
	{
		PushLayer(new EditorLayer());
		
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}