#include "clipboard.h"


Clipboard::Clipboard() {
}

Clipboard::~Clipboard() {
}


char* Clipboard::getClipboardText() {
	/*���µĲ���ϵͳ�У��Ѿ�����Ҫ�ֶ�ʹ��GlobalLock �� GlobalUnlock�������ͽ������ݣ�
	  ������ĳЩ�ϲ���ϵͳ�У���Ȼ��Ҫ
	*/
	// �򿪼�����
	if (!OpenClipboard(nullptr)) {
		std::cout << "�޷��򿪼�����" << std::endl;
		return nullptr;
	}

	// ��ȡ�������е����ݾ��
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr) {
		std::cout << "�޷���ȡ�������е�����" << std::endl;
		CloseClipboard();
		return nullptr;
	}

	// �������ݾ������ȡ����ָ��
	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr) {
		std::cout << "�޷������������е�����" << std::endl;
		CloseClipboard();
		return nullptr;
	}

	// �������ݾ��
	GlobalUnlock(hData);

	// �رռ�����
	CloseClipboard();

	return pszText;
}

void Clipboard::setClipbpardText(const char* text) {

	//�򿪼��а�
	if (!OpenClipboard(nullptr)) {
		std::cout << "�޷��򿪼�����" << std::endl;
		return;
	}

	EmptyClipboard();

	// �����ڴ�
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, strlen(text) + 1);
	if (hHandle == nullptr) {
		std::cout << "�޷������ڴ�" << std::endl;
		CloseClipboard();
		return;
	}

	// ��ȡָ�����ݵ�ָ��
	char* pData = static_cast<char*>(GlobalLock(hHandle));
	if (pData == nullptr) {
		std::cout << "�޷������ڴ�" << std::endl;
		CloseClipboard();
		return;
	}

	// �����ݸ��Ƶ�ȫ���ڴ���
	memcpy(pData, text, strlen(text) + 1);

	// ����ȫ���ڴ�
	GlobalUnlock(hHandle);

	// �����ݾ�������ڼ�������
	SetClipboardData(CF_TEXT, hHandle);

	// �رռ�����
	CloseClipboard();

	Sleep(500);
}
