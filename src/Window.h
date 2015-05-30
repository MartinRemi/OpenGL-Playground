/**
 *	@file window.h
 */

#pragma once

// ----- System include(s)
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <string>

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
		Window(sf::Window &window);

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

		/**
		 *	@brief Draw the content of the window each time it is called.
		 */
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

		/**
		 *	@brief Creates a shader from the content of a file given as parameter.
		 *	@param path The path to the file containing the shader.
		 *	@param shader Out variable containing the filled shader.
		 *	@return true if everything went as expected.
		 */
		bool createShaderFromFile(const std::string &path, GLuint &shader);
};

