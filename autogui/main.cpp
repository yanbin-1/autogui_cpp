#include "main.h"


int main() {

	// --------------------------------------------------------
	// ���а�
	Clipboard* board = new Clipboard();

	// д����а�
	board->setClipbpardText("����д�������1");
	board->setClipbpardText("����д�������2");
	board->setClipbpardText("aaaBBB");

	//��ȡ���а�����
	char* text = board->getClipboardText();
	std::cout << text << std::endl;

	// --------------------------------------------------------
	MouseAutoEvent* mouse_auto_event = new MouseAutoEvent();

	mouse_auto_event->click(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 2);  // �����

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
	// �����¼�
	KeyBoardAutoEvent* keyboard_auto_event = new KeyBoardAutoEvent();
	
	// ���а��¼�
	Clipboard* clipboard_auto_event = new Clipboard();

	const char* message = "aaaBBB�ٺٺٰ�˵��������";
	
	clipboard_auto_event->setClipbpardText(message);
	char* res =	clipboard_auto_event->getClipboardText();
	
	// ��ģ�ⰴ��ʱ��ʹ�õ���������루Virtual Key Codes�����������ַ�����������simulateKeyPress('V')��ģ�ⰴ�´�д��V����������simulateKeyPress('v')���ģ�ⰴ��Сд��v�������������ַ�֮����������Ҫȷ��ʹ����ȷ�����������ģ�ⰴ��������
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
//    std::string text = "Hello, clipboard�ٺٺ�!";
//    writeToClipboard(text);
//    Sleep(500);
//
//    text = "Hello, clipboard�ٺٺ�!1";
//    writeToClipboard(text);
//    Sleep(500);
//
//    text = "Hello, clipboard�ٺٺ�!2";
//    writeToClipboard(text);
//    std::cout << "Text copied to clipboard: " << text << std::endl;
//    return 0;
//}
