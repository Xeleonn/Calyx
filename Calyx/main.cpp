#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Include GLFW and OpenGL headers
#include <iostream>

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

    // Setup OpenGL version (3.3 Core)
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(display_w, display_h, "Calyx", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGuiStyle& style = ImGui::GetStyle();
    //style.FramePadding = ImVec2(10.0f, 10.0f); // Example: 10 pixels padding for frames
    style.WindowPadding = ImVec2(32.0f, 16.0f); // Example: 15 pixels padding for windows

    //style.ItemSpacing.y = 20.0f;

    ImFont* default_font = io.Fonts->AddFontFromFileTTF("../fonts/OpenSans/OpenSans-Medium.ttf", 20.0f);
    ImFont* header_font = io.Fonts->AddFontFromFileTTF("../fonts/OpenSans/OpenSans-Medium.ttf", 32.0f);

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start a new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Window flags: no resize, no move, no collapse, no title bar
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar;

        // Make ImGui window fit the entire GLFW window
        glfwGetFramebufferSize(window, &display_w, &display_h);
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)display_w / 2, (float)display_h));

        ImGui::Begin("Passwords", nullptr, window_flags);
        ImGui::PushFont(header_font);
        ImGui::Text("Your Passwords");
        ImGui::PopFont();
        ImGui::Separator();
        ImGui::Dummy(ImVec2(0, 20.0f)); // Add 20 pixels of vertical space
        ImGui::InputText("Password", buffer, sizeof(buffer), ImGuiInputTextFlags_Password);
        if (buffer)
            ImGui::Text(buffer);
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(display_w / 2, 0));
        ImGui::SetNextWindowSize(ImVec2((float)display_w / 2, (float)display_h));

        ImGui::Begin("Info", nullptr, window_flags);
        ImGui::PushFont(header_font);
        ImGui::Text("Password Information");
        ImGui::PopFont();
        ImGui::End();

        // Rendering
        ImGui::Render();
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
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