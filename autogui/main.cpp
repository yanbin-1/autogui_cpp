#include "main.h"


int main() {

	// --------------------------------------------------------
	// 剪切板
	Clipboard* board = new Clipboard();

	// 写入剪切板
	board->setClipbpardText("这是写入的内容1");
	board->setClipbpardText("这是写入的内容2");
	board->setClipbpardText("aaaBBB");

	//获取剪切板内容
	char* text = board->getClipboardText();
	std::cout << text << std::endl;

	// --------------------------------------------------------
	MouseAutoEvent* mouse_auto_event = new MouseAutoEvent();

	mouse_auto_event->click(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 2);  // 鼠标点击

	POINT point = mouse_auto_event->getPos();
	std::cout << point.x << "\t" << point.y << std::endl;

	mouse_auto_event->move(100, 100);
	point = mouse_auto_event->getPos();
	std::cout << point.x << "\t" << point.y << std::endl;

	SetCursorPos(450, 100);
	point = mouse_auto_event->getPos();
	std::cout << point.x << "\t" << point.y << std::endl;

	mouse_auto_event->lock();

	Sleep(3000);
	mouse_auto_event->move(500, 500);

	mouse_auto_event->unLock();
	
	Sleep(3000);

	mouse_auto_event->roll(100);

	Sleep(3000);

	// ----------------------------------------------
	// 键盘事件
	KeyBoardAutoEvent* keyboard_auto_event = new KeyBoardAutoEvent();
	
	// 剪切板事件
	Clipboard* clipboard_auto_event = new Clipboard();

	const char* message = "aaaBBB嘿嘿嘿案说法二阿文";
	
	clipboard_auto_event->setClipbpardText(message);
	char* res =	clipboard_auto_event->getClipboardText();
	
	// 在模拟按键时，使用的是虚拟键码（Virtual Key Codes），而不是字符。所以输入simulateKeyPress('V')会模拟按下大写的V键，而输入simulateKeyPress('v')则会模拟按下小写的v键。虚拟键码和字符之间有区别，需要确保使用正确的虚拟键码来模拟按键操作。
	keyboard_auto_event->keyDown(VK_CONTROL);
	keyboard_auto_event->keyDown('V');
	keyboard_auto_event->keyUp(VK_CONTROL);
	keyboard_auto_event->keyUp('V');

	std::cout << res << std::endl;

	return 0; 
}




//#include <windows.h>
//#include <iostream>
//
//void writeToClipboard(const std::string& text) {
//    if (!OpenClipboard(nullptr)) {
//        std::cerr << "Failed to open clipboard" << std::endl;
//        return;
//    }
//
//    // Empty the clipboard
//    EmptyClipboard();
//
//    // Allocate global memory for the text
//    HGLOBAL hClipboardData = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
//    if (!hClipboardData) {
//        CloseClipboard();
//        std::cerr << "Failed to allocate memory for clipboard" << std::endl;
//        return;
//    }
//
//    // Lock the memory and get a pointer to it
//    char* pchData = static_cast<char*>(GlobalLock(hClipboardData));
//    if (!pchData) {
//        CloseClipboard();
//        //GlobalFree(hClipboardData);
//        std::cerr << "Failed to lock memory for clipboard" << std::endl;
//        return;
//    }
//
//    // Copy the text into the allocated memory
//    memcpy(pchData, text.c_str(), text.size() + 1);
//
//    // Unlock the memory
//    GlobalUnlock(hClipboardData);
//
//    // Set the clipboard data
//    SetClipboardData(CF_TEXT, hClipboardData);
//
//    // Release the clipboard
//    CloseClipboard();
//}
//
//int main() {
//    Sleep(1000);
//    std::string text = "Hello, clipboard嘿嘿嘿!";
//    writeToClipboard(text);
//    Sleep(500);
//
//    text = "Hello, clipboard嘿嘿嘿!1";
//    writeToClipboard(text);
//    Sleep(500);
//
//    text = "Hello, clipboard嘿嘿嘿!2";
//    writeToClipboard(text);
//    std::cout << "Text copied to clipboard: " << text << std::endl;
//    return 0;
//}
