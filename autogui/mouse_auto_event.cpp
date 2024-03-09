#include "mouse_auto_event.h"

POINT MouseAutoEvent::getPos()
{
	GetCursorPos(&this->point);
	return this->point;
}

void MouseAutoEvent::click(long dwFlags, int click_time)
{
	/*������¼� 
	dwFlags: �������¼�
		MOUSEEVENTF_LEFTDOWN��ģ������������
		MOUSEEVENTF_LEFTUP��ģ��������̧��
		MOUSEEVENTF_RIGHTDOWN��ģ������Ҽ�����
		MOUSEEVENTF_RIGHTUP��ģ������Ҽ�̧��
		MOUSEEVENTF_MIDDLEDOWN��ģ������м�����
		MOUSEEVENTF_MIDDLEUP��ģ������м�̧��
	click_time: �������
	*/

	for (int i = 0; i < click_time; i++) {
		mouse_event(dwFlags, this->point.x, this->point.y, 0, 0);
	}
}

void MouseAutoEvent::leftDown()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::rightDown()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::midDown()
{
	mouse_event(MOUSEEVENTF_MIDDLEDOWN, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::leftUp()
{
	mouse_event(MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::rightUp()
{
	mouse_event(MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::midUp()
{
	mouse_event(MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
}

void MouseAutoEvent::roll(long ch)
{
	// ��ȡ��ǰ���λ��
	this->getPos();

	// �м�����
	mouse_event(MOUSEEVENTF_WHEEL, this->point.x, this->point.y, ch, 0);
}

void MouseAutoEvent::move(int x, int y)
{
	// mouse_event���еĲ�̫��
	SetCursorPos(x, y);
}

void MouseAutoEvent::relativeMove(int x, int y)
{
	// ��ȡ��ǰ���λ��
	this->getPos();

	// ��ȡƫ��λ��
	this->point.x += x;
	this->point.y += y;

	SetCursorPos(this->point.x, this->point.y);
}

void MouseAutoEvent::leftClick(int click_time)
{
	for (int i = 0; i < click_time; i++) {
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, this->point.x, this->point.y, 0, 0);
	}
}

void MouseAutoEvent::rightClick(int click_time)
{
	for (int i = 0; i < click_time; i++) {
		mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, this->point.x, this->point.y, 0, 0);
	}
}

void MouseAutoEvent::midClick(int click_time)
{
	for (int i = 0; i < click_time; i++) {
		mouse_event(MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP, this->point.x, this->point.y, 0, 0);
	}
}

void MouseAutoEvent::lock()
{
	//// ��ȡ��ǰ���λ��
	//this->getPos();

	//// �̶����λ��Ϊ��ǰλ��
	//RECT rt;

	//rt.left = rt.right = this->point.x;
	//rt.bottom = rt.top = this->point.y;
	//ClipCursor(&rt);

	BlockInput(true);
}

void MouseAutoEvent::unLock()
{
	//ClipCursor(NULL);

	BlockInput(false);
}
