#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "gui.h"

// GLFW error callback
static void glfw_error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

int main()
{
    int display_w = 1280;
    int display_h = 720;

    char buffer[256] = "";

    // Setup GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    Window win;
    GLFWwindow* window = win.SetupWindow(display_w, display_h);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    GUI gui;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    gui.BindToWindow(window);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwGetFramebufferSize(window, &display_w, &display_h);

        gui.UpdateGUI(display_w, display_h);
        win.RenderWindow(window, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}