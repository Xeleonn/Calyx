#include "gui.h"

GUI::GUI()
{
	style.WindowPadding = ImVec2(32.0f, 16.0f);
}

void GUI::BindToWindow(GLFWwindow* window)
{
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void GUI::UpdateGUI(int display_w, int display_h)
{
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
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2((float)display_w / 2, (float)display_h));

    ImGui::Begin("Passwords", nullptr, window_flags);
    ImGui::PushFont(header_font);
    ImGui::Text("Your Passwords");
    ImGui::PopFont();
    ImGui::Dummy(ImVec2(0, 5.0f));
    ImGui::Separator();
    ImGui::Dummy(ImVec2(0, 20.0f));
    //ImGui::InputText("Password", buffer, sizeof(buffer), ImGuiInputTextFlags_Password);
    //ImGui::Text(buffer);
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(display_w / 2, 0));
    ImGui::SetNextWindowSize(ImVec2((float)display_w / 2, (float)display_h));

    ImGui::Begin("Info", nullptr, window_flags);
    ImGui::PushFont(header_font);
    ImGui::Text("Password Information");
    ImGui::PopFont();
    ImGui::Dummy(ImVec2(0, 5.0f));
    ImGui::Separator();
    ImGui::End();

    // Rendering
    ImGui::Render();
}