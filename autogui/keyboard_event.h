#pragma once
#include "main.h"

#include <string.h>

class KeyBoardAutoEvent {

public:
	// ����ĳ������
	void pressKey(BYTE bVk);

	// ��סĳ������
	void keyDown(BYTE bVk);

	// �ɿ�ĳ������
	void keyUp(BYTE bVk);

};