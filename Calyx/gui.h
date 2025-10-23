#ifndef GUI_H
#define GUI_H

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <iostream>

class GUI
{
public:
	GUI();

	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();

	ImFont* default_font = io.Fonts->AddFontFromFileTTF("../fonts/OpenSans/OpenSans-Medium.ttf", 20.0f);
	ImFont* header_font = io.Fonts->AddFontFromFileTTF("../fonts/OpenSans/OpenSans-Medium.ttf", 32.0f);

	void BindToWindow(GLFWwindow* window);
	void UpdateGUI(int display_w, int display_h);
};
#endif