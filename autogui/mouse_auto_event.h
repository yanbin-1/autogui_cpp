#pragma once
#include "main.h"


class MouseAutoEvent {

private:
	// 存储鼠标坐标
	POINT point;

public:
	// 移动函数类
	POINT getPos();  // 获取当前鼠标位置，存储在类变量point中

	void move(int x, int y);  // 鼠标移动事件

	void relativeMove(int x, int y);  // 鼠标相对移动

	// 鼠标动作类
	void leftClick(int click_time);  // 左键点击

	void rightClick(int click_time);  // 右键点击

	void midClick(int click_time);  // 中键点击

	void click(long dwFlags, int click_time);  // 鼠标点击事件（废弃）

	// 鼠标按下事件
	void leftDown();  // 左键按下

	void rightDown();  // 右键按下

	void midDown();  // 中键按下

	// 松开事件
	void leftUp();  // 左键松开

	void rightUp();  // 右键松开

	void midUp();  // 中键松开

	// 滚轮
	void roll(long ch);

	// 暂时不考虑
	void lock();  // 锁定鼠标

	void unLock();  // 解除鼠标锁定
};