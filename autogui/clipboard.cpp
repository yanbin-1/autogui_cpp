#include "clipboard.h"


Clipboard::Clipboard() {
}

Clipboard::~Clipboard() {
}


char* Clipboard::getClipboardText() {
	/*在新的操作系统中，已经不需要手动使用GlobalLock 和 GlobalUnlock来锁定和解锁数据，
	  但是在某些老操作系统中，任然需要
	*/
	// 打开剪贴板
	if (!OpenClipboard(nullptr)) {
		std::cout << "无法打开剪贴板" << std::endl;
		return nullptr;
	}

	// 获取剪贴板中的数据句柄
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr) {
		std::cout << "无法获取剪贴板中的数据" << std::endl;
		CloseClipboard();
		return nullptr;
	}

	// 锁定数据句柄，获取数据指针
	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr) {
		std::cout << "无法锁定剪贴板中的数据" << std::endl;
		CloseClipboard();
		return nullptr;
	}

	// 解锁数据句柄
	GlobalUnlock(hData);

	// 关闭剪贴板
	CloseClipboard();

	return pszText;
}

void Clipboard::setClipbpardText(const char* text) {

	//打开剪切板
	if (!OpenClipboard(nullptr)) {
		std::cout << "无法打开剪贴板" << std::endl;
		return;
	}

	EmptyClipboard();

	// 分配内存
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, strlen(text) + 1);
	if (hHandle == nullptr) {
		std::cout << "无法分配内存" << std::endl;
		CloseClipboard();
		return;
	}

	// 获取指向数据的指针
	char* pData = static_cast<char*>(GlobalLock(hHandle));
	if (pData == nullptr) {
		std::cout << "无法锁定内存" << std::endl;
		CloseClipboard();
		return;
	}

	// 将数据复制到全局内存中
	memcpy(pData, text, strlen(text) + 1);

	// 解锁全局内存
	GlobalUnlock(hHandle);

	// 将数据句柄放置在剪贴板上
	SetClipboardData(CF_TEXT, hHandle);

	// 关闭剪贴板
	CloseClipboard();

	Sleep(500);
}
