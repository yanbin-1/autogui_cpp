#include "mouse_auto_event.h"

POINT MouseAutoEvent::getPos()
{
	GetCursorPos(&this->point);
	return this->point;
}

void MouseAutoEvent::click(long dwFlags, int click_time)
{
	/*鼠标点击事件 
	dwFlags: 具体点击事件
		MOUSEEVENTF_LEFTDOWN：模拟鼠标左键按下
		MOUSEEVENTF_LEFTUP：模拟鼠标左键抬起
		MOUSEEVENTF_RIGHTDOWN：模拟鼠标右键按下
		MOUSEEVENTF_RIGHTUP：模拟鼠标右键抬起
		MOUSEEVENTF_MIDDLEDOWN：模拟鼠标中键按下
		MOUSEEVENTF_MIDDLEUP：模拟鼠标中键抬起
	click_time: 点击次数
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
	// 获取当前鼠标位置
	this->getPos();

	// 中键滚动
	mouse_event(MOUSEEVENTF_WHEEL, this->point.x, this->point.y, ch, 0);
}

void MouseAutoEvent::move(int x, int y)
{
	// mouse_event运行的不太对
	SetCursorPos(x, y);
}

void MouseAutoEvent::relativeMove(int x, int y)
{
	// 获取当前鼠标位置
	this->getPos();

	// 获取偏移位置
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
	//// 获取当前鼠标位置
	//this->getPos();

	//// 固定鼠标位置为当前位置
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
