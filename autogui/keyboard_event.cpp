#include "keyboard_event.h"

void KeyBoardAutoEvent::pressKey(BYTE bVk)
{
	// ����ĳ������
	keybd_event(bVk, 0, 0, 0);

	// �ɿ�
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
