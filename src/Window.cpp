// ----- System include(s)
#include <iostream>

// ----- Project include(s)
#include "Window.h"

// ----- Constructor(s)
Window::Window(const sf::Window& w):
window(w)
{
}


Window::~Window( )
{
}

// ----- Public
bool Window::Init(void)
{
	return initOpenGL( );
}

// ----- Private
bool Window::initOpenGL(void)
{
	//Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity( );
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_WIDTH, 0.0, 1.0, -1.0);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity( );

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	//Check for error
	GLenum error = glGetError( );
	if(error != GL_NO_ERROR)
	{
		std::cout <<"Error initializing OpenGL!\n" << std::endl;
		return false;
	}

	return true;
}

