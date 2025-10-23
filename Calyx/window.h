#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

#include <iostream>

class Window
{
public:
	Window();

	GLFWwindow* SetupWindow(int width, int height);
	void RenderWindow(GLFWwindow* window, int &display_w, int &display_h);
};
#endif