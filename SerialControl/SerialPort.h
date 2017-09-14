#pragma once

#include "serial.h"

#define COM_RECVDATA WM_USER + 1

class SerialPort
{
public:
	SerialPort();
	~SerialPort();


private:
	static serial::Serial m_Port;
	static bool isOpen;
	HANDLE ThreadHandle;

public:
	static HWND WndHandle;

public:
	bool OpenPort(CString port);

private:
	static DWORD WINAPI  ThreadReceiveData(LPVOID lpParameter);

	char ConvertHexChar(char ch);
	int String2Hex(CString str, CByteArray& senddate);

public:
	//�رմ���
	bool ClosePort();
	//���ʹ�������
	int WritePort(CString data);
	//��ȡ��������
	CString ReadPort();
	//���ջ�������������
	bool Available();
	//����״̬
	bool IsOpen();
};

