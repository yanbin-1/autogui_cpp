#include "image_auto_event.h"


std::unordered_map<std::string, float> ImageAutoEvent::getMainScreenResolution()
{
    //获取dpi，需要除以默认dpi_init=96.0才能得到放大倍数
    int dpi = GetDpiForWindow(this->hwnd);
    float scaling_factor = dpi / this->dpi_init;

    float screen_width = GetSystemMetrics(SM_CXSCREEN) * scaling_factor; 
    float screen_height = GetSystemMetrics(SM_CYSCREEN) * scaling_factor; 

    std::unordered_map<std::string, float> screen_resolution;
    screen_resolution["width"] = screen_width;
    screen_resolution["height"] = screen_height;

    return screen_resolution;
}

cv::Mat ImageAutoEvent::getMainScreenImage(std::unordered_map<std::string, float> screen_resolution)
{
    float screen_width = screen_resolution["width"];
    float screen_height = screen_resolution["height"];

    // 创建一个mat对象来存放结果
    cv::Mat src(screen_height, screen_width, CV_8UC4);

    // 创建一个bitmap
    HBITMAP hbwindow = CreateCompatibleBitmap(this->hwindowDC, screen_width, screen_height);
    BITMAPINFOHEADER  bi = { 0 };
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = screen_width;
    bi.biHeight = -screen_height;  //这使得图像在Mat中不会倒置
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;

    // 使用BitBlt拷贝像素
    SelectObject(this->hwindowCompatibleDC, hbwindow);
    BitBlt(this->hwindowCompatibleDC, 0, 0, screen_width, screen_height, this->hwindowDC, 0, 0, SRCCOPY);
    GetDIBits(this->hwindowCompatibleDC, hbwindow, 0, screen_height, src.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // 释放资源
    DeleteObject(hbwindow);
    DeleteDC(this->hwindowCompatibleDC);
    ReleaseDC(this->hwnd, this->hwindowDC);

    return src;
}

POINT ImageAutoEvent::getImageLocation(std::string image_path)
{
    return POINT();
}
