#include "keyboard_event.h"

void KeyBoardAutoEvent::pressKey(BYTE bVk)
{
	// 按下某个按键
	keybd_event(bVk, 0, 0, 0);

	// 松开
	keybd_event(bVk, 0, KEYEVENTF_KEYUP, 0);
}

void KeyBoardAutoEvent::keyDown(BYTE bVk)
{
	keybd_event(bVk, 0, 0, 0);
}

void KeyBoardAutoEvent::keyUp(BYTE bVk)
{
	keybd_event(bVk, 0, KEYEVENTF_KEYUP, 0);
}
