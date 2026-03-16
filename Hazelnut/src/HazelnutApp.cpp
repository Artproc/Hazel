#include <Hazel.h>
#include "Hazel\Core\EntryPoint.h"

#include "EditorLayer.h"

namespace Hazel {

	class Hazelnut : public Application
	{
	public:
		Hazelnut()
			: Application("Hazelnut Editor")
		{
			PushLayer(new EditorLayer());
		}
		~Hazelnut()
		{
		}
	};

	Hazel::Application* CreateApplication()
	{
		return new Hazelnut();
	}
}