workspace "Gale-Engine"
   architecture "x86"
   configurations { "Debug", "Release", "Dist" }
   startproject "Gale-Engine-App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
   include "SFML"

group "Core"
	include "Gale-Engine-Core/Build-Core.lua"

group "Applications"
include "Gale-Engine-App/Build-App.lua"