project "Gale-Engine-Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   vpaths 
   {
      -- General header and source
      ["Header/*"] = { "Source/Gale/**/*.h" },
      ["Source/*"] = { "Source/Gale/**/*.cpp" },

      -- Specific subfolders
      ["Header/System"] = { "Source/Gale/System/*.h" },
      ["Header/Graphics"] = { "Source/Gale/Graphics/*.h" },
      ["Source/System"] = { "Source/Gale/System/*.cpp" },
      ["Source/Graphics"] = { "Source/Gale/Graphics/*.cpp" }
   }

   includedirs
   {
      "Source",

      -- Include SFML
      "$(SolutionDir)SFML/include"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

       libdirs { "$(SolutionDir)SFML/lib"}

   filter "configurations:Debug"
       defines { "DEBUG", "SFML_STATIC" }
       runtime "Debug"
       symbols "On"
       links {
            -- SMFL debug libaries
            "sfml-graphics-s-d.lib",
            "sfml-window-s-d.lib",
            "sfml-audio-s-d.lib",
            "sfml-network-s-d.lib",
            "sfml-system-s-d.lib",

            -- additional libaries
            "opengl32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "openal32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
       }

   filter "configurations:Release"
       defines { "RELEASE", "SFML_STATIC" }
       runtime "Release"
       optimize "On"
       symbols "On"
       links {
            -- SFML release libaries
            "sfml-graphics-s.lib",
            "sfml-window-s.lib",
            "sfml-audio-s.lib",
            "sfml-network-s.lib",
            "sfml-system-s.lib",

            -- additional libaries
            "opengl32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "openal32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
       }

   filter "configurations:Dist"
       defines { "DIST", "SFML_STATIC" }
       runtime "Release"
       optimize "On"
       symbols "Off"
       links {
        -- SFML release libaries
        "sfml-graphics-s.lib",
        "sfml-window-s.lib",
        "sfml-audio-s.lib",
        "sfml-network-s.lib",
        "sfml-system-s.lib",

        -- additional libaries
        "opengl32.lib",
        "freetype.lib",
        "winmm.lib",
        "gdi32.lib",
        "openal32.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "ws2_32.lib"
   }