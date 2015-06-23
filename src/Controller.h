#pragma once
class Controller
{
	public:
		// Constructor(s) - Destructor(s)
		Controller();
		~Controller();

		// Method(s)
		bool _Connect(void);
	protected:
		/**@brief Index in system's controllers array*/
		unsigned short _index;
		/**@brief Indicates if the controller is connected.*/
		bool _connected;

		// ----- Static function(s)

	private:
};

