#pragma once
#include <stdio.h>

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();
	
int main(int argc, char* argv)
{
	printf("Woo-Hoo, it worked!!!\n");
	auto app = Hazel::CreateApplication();
	app->Run();

	delete app;
}
#endif // HZ_PLATFORM_WINDOWS
