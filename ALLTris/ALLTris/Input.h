#ifndef INPUT_H
#define INPUT_H

#include <windows.h>

class Input {
public:
	static bool isKeyDown(int key);
	static const int ENTER = VK_RETURN;
	static const int SPACE = VK_SPACE;
	static const int upArrow = VK_UP;
	static const int downArrow = VK_DOWN;
	static const int leftArrow = VK_LEFT;
	static const int rightArrow = VK_RIGHT;
	static const int CONTROL = VK_CONTROL;

	static const int KEY_C = 0x43;
	
private:
};

#endif // !INPUT_H
