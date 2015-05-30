#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool initOpenGL( )
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
		printf("Error initializing OpenGL! %s\n");
		return false;
	}

	return true;
}

int main( )
{
	// create the window
	sf::Window window(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);

	// load resources, initialize the OpenGL states, ...
	initOpenGL( );

	// run the main loop
	bool running = true;
	while(running)
	{
		// handle events
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				// end the program
				running = false;
			}
			else if(event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}

		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw...

		// end the current frame (internally swaps the front and back buffers)
		window.display( );
	}

	// release resources...

	return 0;
}