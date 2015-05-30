// ----- System include(s)

// ----- Project include(s)
#include "window.h"

int main( )
{
	// create the window
	sf::Window sf_w(sf::VideoMode(SCREEN_WIDTH, SCREEN_WIDTH), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
	sf_w.setVerticalSyncEnabled(true);

	Window window(sf_w);
	window.Init( );

	// run the main loop
	bool running = true;
	while(running)
	{
		// handle events
		sf::Event event;
		while(sf_w.pollEvent(event))
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

		window.Draw( );
	}

	// release resources...

	return 0;
}