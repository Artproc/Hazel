#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel
{


	Application::Application() = default;

	Application::~Application() = default;

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE(fmt::streamed(e));
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE(fmt::streamed(e));
		}

		while (true);
	}

}