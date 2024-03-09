#pragma once
#include "main.h"


class ImageAutoEvent {
public:

	// 根据所给路径检测屏幕中图像的中心位置
	POINT getImageLocation(std::string image_path);
	
};