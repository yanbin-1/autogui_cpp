#pragma once
#include "main.h"

#include "opencv2/opencv.hpp"
#include <ShellScalingApi.h>
#include <unordered_map>

#pragma comment(lib, "Shcore.lib")


class ImageAutoEvent {

private:
	// Ĭ��dpi
	float dpi_init = 96.0;

	// �����ھ��
	HWND hwnd;

	// ��ȡ��Ļ���豸������
	HDC hwindowDC;
	HDC hwindowCompatibleDC;


public:

	ImageAutoEvent() {
		// ��ȡ�����ھ��
		this->hwnd = GetDesktopWindow();

		// ��ȡ��Ļ���豸������
		this->hwindowDC = GetDC(hwnd);
		this->hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

		SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);
	};

	// ��ȡ����Ļ�ֱ���
	std::unordered_map<std::string, float>  getMainScreenResolution();

	// ��ȡ����Ļ����
	cv::Mat getMainScreenImage(std::unordered_map<std::string, float> screen_resolution);

	// ��������·�������Ļ��ͼ�������λ��
	POINT getImageLocation(std::string image_path);
	
};