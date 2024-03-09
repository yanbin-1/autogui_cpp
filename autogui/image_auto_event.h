#pragma once
#include "main.h"

#include "opencv2/opencv.hpp"
#include <ShellScalingApi.h>
#include <unordered_map>

#pragma comment(lib, "Shcore.lib")


class ImageAutoEvent {

private:
	// 默认dpi
	float dpi_init = 96.0;

	// 主窗口句柄
	HWND hwnd;

	// 获取屏幕的设备上下文
	HDC hwindowDC;
	HDC hwindowCompatibleDC;


public:

	ImageAutoEvent() {
		// 获取主窗口句柄
		this->hwnd = GetDesktopWindow();

		// 获取屏幕的设备上下文
		this->hwindowDC = GetDC(hwnd);
		this->hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

		SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);
	};

	// 获取主屏幕分辨率
	std::unordered_map<std::string, float>  getMainScreenResolution();

	// 获取主屏幕截屏
	cv::Mat getMainScreenImage(std::unordered_map<std::string, float> screen_resolution);

	// 根据所给路径检测屏幕中图像的中心位置
	POINT getImageLocation(std::string image_path);
	
};