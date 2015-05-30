/**
 *	@file window.h
 */

#pragma once

// ----- System include(s)
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

// ----- Project include(s)
#include "utils.h"

/**
 *	@brief Class Window that handles screen display.
 *
 *	This class uses OpenGL and a SFML context.
 */
class Window
{
	public:
		// ----- Constructor(s)
		/**
		 *	@brief Constructor of window class.
		 *	
		 *	@param window The SFML window used to display content to the screen.
		 */
		Window(sf::Window& window);

		/**
		 *	@brief Window destructor.
		 *
		 *	Currently doing nothing.
		 */
		~Window( );

		// ----- Method(s)
		/**
		 *	@brief Method used to initialize the context of the window.
		 *	@return true if everything went as expected.
		 */
		bool Init(void);

		void Draw(void);

	private:
		// ----- Member(s)
		/**@brief SFML Window objet used as an OpenGL context.*/
		sf::Window& window;

		// ----- Method(s)
		/**
		 *	@brief Method used to initialize every ressource needed to properly work with OpenGL.
		 *	@return true if everything went as expected.
		 */
		bool initOpenGL(void);
};

