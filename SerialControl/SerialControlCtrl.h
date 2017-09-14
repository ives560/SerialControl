#pragma once

#include "serial.h"
#include "SerialPort.h"

// SerialControlCtrl.h : CSerialControlCtrl ActiveX �ؼ����������


// CSerialControlCtrl : �й�ʵ�ֵ���Ϣ������� SerialControlCtrl.cpp��

class CSerialControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSerialControlCtrl)

// ���캯��
public:
	CSerialControlCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CSerialControlCtrl();

	DECLARE_OLECREATE_EX(CSerialControlCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CSerialControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSerialControlCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CSerialControlCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
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

