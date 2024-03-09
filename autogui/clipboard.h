#pragma once
#include "main.h"

class Clipboard {
public:
	Clipboard();
	~Clipboard();

	// 获取剪切板中的文字
	char* getClipboardText();

	// 往剪切板中写入文字
	void setClipbpardText(const char* text);

};

