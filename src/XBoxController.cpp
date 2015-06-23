#include "XBoxController.h"

std::atomic<bool> XBoxController::controllersUsed[XUSER_MAX_COUNT] = { false };

// ----- Constructor(s) - Destructor(s)
XBoxController::XBoxController()
{
	_index = XUSER_MAX_COUNT; // False/default value
	_connected = false;
}


XBoxController::~XBoxController()
{
}

// ----- Public
bool XBoxController::_Connect()
{
	if (!_connected)
	{
		for (unsigned short i = 0; i < XUSER_MAX_COUNT; ++i)
		{
			if (!XBoxController::controllersUsed[i])
			{
				_index = i;
				if (_getState() == ERROR_SUCCESS)
				{
					_connected = true;
					return true;
				}
				// else
				_index = -1;
			}
		}
	}
	return false;
}

bool XBoxController::_Update(void)
{
	return _getState() == ERROR_SUCCESS;
}

// ----- Private
DWORD XBoxController::_getState(void)
{
	ZeroMemory(&_state, sizeof(XINPUT_STATE));

	return XInputGetState(_index, &_state);
}
