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
	//关闭串口
	bool ClosePort();
	//发送串口数据
	int WritePort(CString data);
	//读取串口数据
	CString ReadPort();
	//接收缓冲区有无数据
	bool Available();
	//串口状态
	bool IsOpen();
};

