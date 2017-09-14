#include "stdafx.h"
#include "SerialPort.h"


bool SerialPort::isOpen = false;

serial::Serial SerialPort::m_Port;

HWND SerialPort::WndHandle = NULL;

SerialPort::SerialPort()
{
	ThreadHandle = NULL;
}


SerialPort::~SerialPort()
{
}


//接收线程
DWORD WINAPI  SerialPort::ThreadReceiveData(LPVOID lpParameter)
{
	int len = 0;
	int oldlen = 0;
	while (isOpen == true)
	{
		len = m_Port.available();
		if (len>0 && oldlen!=len)
		{
			::PostMessageA(WndHandle, COM_RECVDATA, NULL, NULL);
		}

		oldlen = len;
		Sleep(1);

	}
	return 0;
}

//打开串口
bool SerialPort::OpenPort(CString port)
{
	try
	{
		const std::string str = (CStringA)port;
		m_Port.setPort(str);
		m_Port.open();
		if (m_Port.isOpen() == true)
		{
			isOpen = true;
			if (ThreadHandle == NULL)
			{
				ThreadHandle = CreateThread(NULL, 0, ThreadReceiveData, NULL, 0, NULL);
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (std::exception e)
	{
		return false;
	}

}

//关闭串口
bool SerialPort::ClosePort()
{
	try
	{
		isOpen = false;
		if (ThreadHandle != NULL)
		{
			WaitForSingleObject(ThreadHandle, INFINITE);
		}
		ThreadHandle = NULL;
		m_Port.close();

		if (m_Port.isOpen() == true)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (std::exception e)
	{
		return false;
	}

}

//串口状态
bool SerialPort::IsOpen()
{
	return m_Port.isOpen();
}

//发送串口数据
int SerialPort::WritePort(CString data)
{
	CByteArray hexdate;
	int len = String2Hex((CString)data, hexdate);
	uint8_t* buffer = (uint8_t*)hexdate.GetData();
	return m_Port.write(buffer, len);
}

//读取串口数据
CString SerialPort::ReadPort()
{
	int len = m_Port.available();
	CString data( m_Port.read(len).c_str());
	return data;
}

//接收缓冲区有无数据
bool SerialPort::Available()
{
	if (m_Port.available() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


char SerialPort::ConvertHexChar(char ch)
{
	if (ch >= '0'&& ch <= '9')
	{
		return ch - 0x30;
	}
	else if (ch >= 'A'&& ch <= 'F')
	{
		return ch - 'A' + 10;
	}
	else if (ch >= 'a'&& ch <= 'f')
	{
		return ch - 'a' + 10;
	}
	else
	{
		return -1;
	}
}


int SerialPort::String2Hex(CString str, CByteArray& senddate)
{
	int hexdate, lowhexdate;
	int hexdatelen = 0;
	int len = str.GetLength();
	senddate.SetSize(len / 2);

	for (int i = 0; i < len;)
	{
		char lstr, hstr = str[i];
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		lstr = str[i];
		hexdate = ConvertHexChar(hstr);
		lowhexdate = ConvertHexChar(lstr);
		if (hexdate == 16 || lowhexdate == 16)
			break;
		else
		{
			hexdate = hexdate * 16 + lowhexdate;
		}
		i++;
		senddate[hexdatelen] = (char)hexdate;
		hexdatelen++;
	}
	senddate.SetSize(hexdatelen);
	return hexdatelen;
}

