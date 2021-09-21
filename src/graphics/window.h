#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

namespace rabona { namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window
	{
	public:
		
	private:
		
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Close;
		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		double mx, my;
	public:
		Window(const char* name, int width, int  height);
		~Window();
		bool closed() const;
		void update();
		void clear() const;
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const {return m_Height; }
		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int mousebuttons) const;
		void getMousePosition(double& x, double& y) const;
	
	
	private:
		bool init();
		friend static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_calback(GLFWwindow* window, double xpos, double ypos);
		


		};

}}
