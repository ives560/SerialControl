#pragma once

#include "serial.h"
#include "SerialPort.h"

// SerialControlCtrl.h : CSerialControlCtrl ActiveX 控件类的声明。


// CSerialControlCtrl : 有关实现的信息，请参阅 SerialControlCtrl.cpp。

class CSerialControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSerialControlCtrl)

// 构造函数
public:
	CSerialControlCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CSerialControlCtrl();

	DECLARE_OLECREATE_EX(CSerialControlCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CSerialControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSerialControlCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CSerialControlCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		eventidOnComm = 12L,
		dispidWrite = 12L,
		dispidSetParity = 11L,
		dispidSetStopBits = 10L,
		dispidSetByteSize = 9L,
		dispidSetBaudRate = 8L,
		dispidReadPort = 7L,
		dispidAvailable = 6L,
		dispidIsOpen = 1L,
		dispidClosePort = 5L,
		dispidWritePort = 4L,
		dispidOpenPort = 3L,
		dispidSetPort = 2L
	};

private:
	serial::Serial m_serial;
	SerialPort m_port;

protected:
	void SetPort(BSTR port);
	LONG OpenPort(BSTR port);
	LONG WritePort(BSTR data);
	LONG ClosePort();
	LONG IsOpen();
	LONG Available();
	BSTR ReadPort();
	void SetBaudRate(LONG baudrate);
	void SetByteSize(LONG bytesize);
	void SetStopBits(LONG stopbits);
	void SetParity(LONG parity);

protected:
	afx_msg LRESULT OnRecvData(WPARAM wParam, LPARAM lParam);

	void OnComm()
	{
		FireEvent(eventidOnComm, EVENT_PARAM(VTS_NONE));
	}
};

