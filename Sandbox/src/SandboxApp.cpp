#include <Hazel.h>
#include "Hazel\Core\EntryPoint.h"

#include "ExampleLayer.h"
#include "Sandbox2D.h"


class SandBox : public Hazel::Application
{
public:
	SandBox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	~SandBox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}