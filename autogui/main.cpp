#include "main.h"


int main() {
	ImageAutoEvent* image_auto_event = new ImageAutoEvent();
	std::unordered_map<std::string, float> screen_resolution = image_auto_event->getMainScreenResolution();
	cv::Mat src = image_auto_event->getMainScreenImage(screen_resolution);

	// ��ʾ��ȡ��ȫ��ͼ��
	cv::imshow("Screen Capture", src);
	cv::waitKey(0);

	Sleep(100000);

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
	char* res = clipboard_auto_event->getClipboardText();

	// ��ģ�ⰴ��ʱ��ʹ�õ���������루Virtual Key Codes�����������ַ�����������simulateKeyPress('V')��ģ�ⰴ�´�д��V����������simulateKeyPress('v')���ģ�ⰴ��Сд��v�������������ַ�֮����������Ҫȷ��ʹ����ȷ�����������ģ�ⰴ��������
	keyboard_auto_event->keyDown(VK_CONTROL);
	keyboard_auto_event->keyDown('V');
	keyboard_auto_event->keyUp(VK_CONTROL);
	keyboard_auto_event->keyUp('V');

	std::cout << res << std::endl;

	return 0;
}
