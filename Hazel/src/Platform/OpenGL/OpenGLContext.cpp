#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hazel {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		HZ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		HZ_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		HZ_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
		HZ_CORE_INFO("  Supported glsl version: {0}", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
		
		int maxTextureSamplers;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureSamplers);
		HZ_CORE_INFO("  Max Texture Samplers:: {0}", maxTextureSamplers);

		//I just wanted to know what these values 
		int maxRenderbufferSize;
		glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &maxRenderbufferSize);
		HZ_CORE_INFO("  Max Renderbuffer Size: {0}", maxRenderbufferSize);

		int maxTextureSize;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
		HZ_CORE_INFO("  Max Texture Size: {0}", maxTextureSize);

		int max_dims[2];
		glGetIntegerv(GL_MAX_VIEWPORT_DIMS, max_dims);
		HZ_CORE_INFO("  Max Viewport Dims: {0} x {1}", max_dims[0], max_dims[1]);

		#ifdef HZ_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);


			HZ_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		HZ_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}
}
