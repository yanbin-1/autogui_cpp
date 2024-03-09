#pragma once
#include "main.h"


class MouseAutoEvent {

private:
	// �洢�������
	POINT point;

public:
	// �ƶ�������
	POINT getPos();  // ��ȡ��ǰ���λ�ã��洢�������point��

	void move(int x, int y);  // ����ƶ��¼�

	void relativeMove(int x, int y);  // �������ƶ�

	// ��궯����
	void leftClick(int click_time);  // ������

	void rightClick(int click_time);  // �Ҽ����

	void midClick(int click_time);  // �м����

	void click(long dwFlags, int click_time);  // ������¼���������

	// ��갴���¼�
	void leftDown();  // �������

	void rightDown();  // �Ҽ�����

	void midDown();  // �м�����

	// �ɿ��¼�
	void leftUp();  // ����ɿ�

	void rightUp();  // �Ҽ��ɿ�

	void midUp();  // �м��ɿ�

	// ����
	void roll(long ch);

	// ��ʱ������
	void lock();  // �������

	void unLock();  // ����������
};