#pragma once
#include "main.h"

class Clipboard {
public:
	Clipboard();
	~Clipboard();

	// ��ȡ���а��е�����
	char* getClipboardText();

	// �����а���д������
	void setClipbpardText(const char* text);

};

