// ----- System include(s)
#include <iostream>

// ----- Project include(s)
#include "Window.h"

// ----- Constructor(s)
Window::Window(sf::Window& w):
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

void Window::Draw(void)
{
	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	// Generating buffers
	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// end the current frame (internally swaps the front and back buffers)
	window.display( );
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

