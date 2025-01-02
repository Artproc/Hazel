workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	project "Hazel"
		location "Hazel"
		kind "SharedLib"
		language "C++"

		outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}
		
		filter "system:windows"
			cppdialect "C++17"
			staticruntime "on"
			systemversion "latest"

			defines
			{
				"HZ_PLATFORM_WINDOWS",
				"HZ_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/utf-8 "
			symbols "on"

		filter "configurations:Release"
			defines "HZ_RELEASE"
			buildoptions "/utf-8 "
			optimize "on"

		filter "configurations:Dist"
			defines "HZ_DIST"
			buildoptions "/utf-8 "
			optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Hazel/vendor/spdlog/include",
			"Hazel/src"
		}

		links
		{
			"Hazel"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "on"
			systemversion "latest"

			defines
			{
				"HZ_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/utf-8 "
			symbols "on"

		filter "configurations:Release"
			defines "HZ_RELEASE"
			buildoptions "/utf-8 "
			optimize "on"

		filter "configurations:Dist"
			defines "HZ_DIST"
			buildoptions "/utf-8 "
			optimize "on"