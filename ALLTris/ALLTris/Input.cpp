#include "Input.h"
#include <windows.h>

bool Input::isKeyDown(int key) {
	return GetAsyncKeyState(key) & 0x8000;
}


