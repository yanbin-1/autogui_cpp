#include "main.h"


int main() {
	ImageAutoEvent* image_auto_event = new ImageAutoEvent();
	std::unordered_map<std::string, float> screen_resolution = image_auto_event->getMainScreenResolution();
	cv::Mat src = image_auto_event->getMainScreenImage(screen_resolution);

	// 显示截取的全屏图像
	cv::imshow("Screen Capture", src);
	cv::waitKey(0);

	Sleep(100000);

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
	char* res = clipboard_auto_event->getClipboardText();

	// 在模拟按键时，使用的是虚拟键码（Virtual Key Codes），而不是字符。所以输入simulateKeyPress('V')会模拟按下大写的V键，而输入simulateKeyPress('v')则会模拟按下小写的v键。虚拟键码和字符之间有区别，需要确保使用正确的虚拟键码来模拟按键操作。
	keyboard_auto_event->keyDown(VK_CONTROL);
	keyboard_auto_event->keyDown('V');
	keyboard_auto_event->keyUp(VK_CONTROL);
	keyboard_auto_event->keyUp('V');

	std::cout << res << std::endl;

	return 0;
}
