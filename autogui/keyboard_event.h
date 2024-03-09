#pragma once
#include "main.h"

#include <string.h>

class KeyBoardAutoEvent {

public:
	// 按下某个按键
	void pressKey(BYTE bVk);

	// 按住某个按键
	void keyDown(BYTE bVk);

	// 松开某个按键
	void keyUp(BYTE bVk);

};