#include "image_auto_event.h"


std::unordered_map<std::string, float> ImageAutoEvent::getMainScreenResolution()
{
    //��ȡdpi����Ҫ����Ĭ��dpi_init=96.0���ܵõ��Ŵ���
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

    // ����һ��mat��������Ž��
    cv::Mat src(screen_height, screen_width, CV_8UC4);

    // ����һ��bitmap
    HBITMAP hbwindow = CreateCompatibleBitmap(this->hwindowDC, screen_width, screen_height);
    BITMAPINFOHEADER  bi = { 0 };
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = screen_width;
    bi.biHeight = -screen_height;  //��ʹ��ͼ����Mat�в��ᵹ��
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;

    // ʹ��BitBlt��������
    SelectObject(this->hwindowCompatibleDC, hbwindow);
    BitBlt(this->hwindowCompatibleDC, 0, 0, screen_width, screen_height, this->hwindowDC, 0, 0, SRCCOPY);
    GetDIBits(this->hwindowCompatibleDC, hbwindow, 0, screen_height, src.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // �ͷ���Դ
    DeleteObject(hbwindow);
    DeleteDC(this->hwindowCompatibleDC);
    ReleaseDC(this->hwnd, this->hwindowDC);

    return src;
}

POINT ImageAutoEvent::getImageLocation(std::string image_path)
{
    return POINT();
}
