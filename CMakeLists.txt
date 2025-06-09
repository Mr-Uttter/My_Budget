cmake_minimum_required(VERSION 3.15)
project(My_Budget CXX) # Projektets namn, påverkar inte .exe-filens namn direkt

# Ange standard för C++ (rekommenderas starkt att vara explicita)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # För att säkerställa standardkompatibilitet

# Lägg till underkatalog för GLFW.
# GLFW har en egen CMakeLists.txt och byggs som ett separat bibliotek.
add_subdirectory(ext/glfw)

# Definiera källfiler för din huvudapplikation.
# Detta inkluderar dina egna filer samt ImGui-filerna.
set(APP_SOURCES
    src/main.cpp
    src/application.cpp

    # ImGui källfiler (från ext/imgui)
    ext/imgui/imgui.cpp
    ext/imgui/imgui_demo.cpp
    ext/imgui/imgui_draw.cpp
    ext/imgui/imgui_tables.cpp
    ext/imgui/imgui_widgets.cpp

    # ImGui backends - Välj den/de som passar din rendering (t.ex. OpenGL3 med GLFW)
    ext/imgui/backends/imgui_impl_glfw.cpp
    ext/imgui/backends/imgui_impl_opengl3.cpp
)

# Lägg till din huvudapplikation.
# Namnet "My_Budget" här blir namnet på din exekverbara fil (My_Budget.exe).
add_executable(My_Budget ${APP_SOURCES})

# Sätt utdatamappen för den exekverbara filen
# Din My_Budget kommer att hamna i din build-mapp/output
set_target_properties(My_Budget PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
    # Du kan även specificera för olika byggkonfigurationer om du använder dem:
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/output/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/output/Release"
)

# Inkludera mappar där kompilatorn ska söka efter headerfiler.
target_include_directories(My_Budget PUBLIC
    ${CMAKE_SOURCE_DIR}/src                  # Dina egna headerfiler
    ${CMAKE_SOURCE_DIR}/ext/imgui            # ImGui's huvud-headerfiler (imgui.h, imconfig.h)
    ${CMAKE_SOURCE_DIR}/ext/imgui/backends   # ImGui's backend-headerfiler
    ${CMAKE_SOURCE_DIR}/ext/imgui/misc/cpp   #
)

# Länka din applikation till de bibliotek den använder.
# OBS: Namnen nedan (glfw, OpenXLSX) är de namn som DEFINIERAS
# i respektive biblioteks CMakeLists.txt-fil via "add_library()".
target_link_libraries(My_Budget
    glfw                # Länkar till GLFW-biblioteket som byggs från ext/glfw
    opengl32            # Standard OpenGL-bibliotek för Windows
    # Lägg till andra systembibliotek om de behövs (t.ex. Gdi32 för Windows GUI, om inte redan hanterat av GLFW)
) 
