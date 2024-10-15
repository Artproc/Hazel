#pragma once

#include "hzpch.h"
#include "Hazel/Core/Layer.h"


namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		ImGuiLayer(const std::string& name);
		virtual ~ImGuiLayer();

		void OnAttach()override;
		void OnDetach()override;
		void OnUpdate() override;
		
	
	private:
		float m_Time = 0.0f;
	};
}