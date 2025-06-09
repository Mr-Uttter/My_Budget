#include "application.h"            // Include our own header
#include <iostream>                 // For std::cout
#include <glad/glad.h>
#include <KHR/khrplatform.h>
#include <GLFW/glfw3.h>             // For GLFW (creates windows)
#include "imgui_impl_glfw.h"        // Handling windows and gui
#include "imgui_impl_opengl3.h"     // GUI

Application app; // Init GUI app

GLFWwindow* InitWindow(int width, int height, const char* title);

int main(void){

    Menu menu;
    
    GLFWwindow* win = InitWindow(1280, 720, "My Budget");
    if (!win) {
        std::cerr << "Could not create window\n";
        return -1;
    }

    glfwMakeContextCurrent(win);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; // Used later
    ImGui::StyleColorsDark(); // Colors
    ImGui_ImplGlfw_InitForOpenGL(win, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    

    while (!glfwWindowShouldClose(win)) {
        glfwPollEvents(); // Handle input

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        // Draw GUI
        ImGui::NewFrame();

        app.Render();
        if(menu.setMenu()){
            break;
        }

        // Rendera
        ImGui::Render();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Should be BG color
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(win);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(win);
    glfwTerminate();

    return 0;
}


GLFWwindow* InitWindow(int width, int height, const char* title) {
    /* Windowsettings for viewport */
    glfwInit();
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);      // No border
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);       // Allow resizing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);   // OpenGL stuff
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!win) return nullptr;

    // Center Window
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xpos = (mode->width - width) / 2;
    int ypos = (mode->height - height) / 2;
    glfwSetWindowPos(win, xpos, ypos);

    glfwMakeContextCurrent(win);
    glfwSwapInterval(1); // V-sync
    return win;
}
