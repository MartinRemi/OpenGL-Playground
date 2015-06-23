#pragma once

// System include(s)
#include <atomic>
#include <Windows.h>
#include <Xinput.h>

// Project include(s)
#include "Controller.h"

class XBoxController :
	public Controller
{
	public:
		// Constructor(s) - Destructor(s)
		XBoxController();
		~XBoxController();

		// Method(s)
		bool _Connect(void);
		bool _Update(void);
	protected:
	private:
		// ----- Static member(s)
		static std::atomic<bool> controllersUsed[XUSER_MAX_COUNT];

		// ----- Member(s)
		XINPUT_STATE _state;
		
		// ----- Function(s)
		DWORD _getState(void);
};

