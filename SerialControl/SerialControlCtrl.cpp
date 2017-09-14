// SerialControlCtrl.cpp : CSerialControlCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "SerialControl.h"
#include "SerialControlCtrl.h"
#include "SerialControlPropPage.h"
#include "afxdialogex.h"
#include "comutil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSerialControlCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CSerialControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
ON_MESSAGE(COM_RECVDATA, &CSerialControlCtrl::OnRecvData)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CSerialControlCtrl, COleControl)
	DISP_FUNCTION_ID(CSerialControlCtrl, "SetPort", dispidSetPort, SetPort, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CSerialControlCtrl, "OpenPort", dispidOpenPort, OpenPort, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CSerialControlCtrl, "WritePort", dispidWritePort, WritePort, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CSerialControlCtrl, "ClosePort", dispidClosePort, ClosePort, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CSerialControlCtrl, "IsOpen", dispidIsOpen, IsOpen, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CSerialControlCtrl, "Available", dispidAvailable, Available, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CSerialControlCtrl, "ReadPort", dispidReadPort, ReadPort, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CSerialControlCtrl, "SetBaudRate", dispidSetBaudRate, SetBaudRate, VT_EMPTY, VTS_I4)
	DISP_FUNCTION_ID(CSerialControlCtrl, "SetByteSize", dispidSetByteSize, SetByteSize, VT_EMPTY, VTS_I4)
	DISP_FUNCTION_ID(CSerialControlCtrl, "SetStopBits", dispidSetStopBits, SetStopBits, VT_EMPTY, VTS_I4)
	DISP_FUNCTION_ID(CSerialControlCtrl, "SetParity", dispidSetParity, SetParity, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CSerialControlCtrl, COleControl)
	EVENT_CUSTOM_ID("OnComm", eventidOnComm, OnComm, VTS_NONE)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CSerialControlCtrl, 1)
	PROPPAGEID(CSerialControlPropPage::guid)
END_PROPPAGEIDS(CSerialControlCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CSerialControlCtrl, "SERIALCONTROL.SerialControlCtrl.1",
	0x436434f0, 0xf9b7, 0x4f57, 0x82, 0x5a, 0xa2, 0xfb, 0xac, 0x86, 0xe, 0x7e)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CSerialControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DSerialControl = { 0x83F42EEB, 0x9C7D, 0x4745, { 0xB1, 0xD6, 0xC9, 0xE5, 0x3A, 0xFB, 0xEF, 0xD1 } };
const IID IID_DSerialControlEvents = { 0xD3CF1561, 0xAB30, 0x427F, { 0xA0, 0xA9, 0x6A, 0xF1, 0x9D, 0x28, 0xD4, 0x49 } };

// �ؼ�������Ϣ

static const DWORD _dwSerialControlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSerialControlCtrl, IDS_SERIALCONTROL, _dwSerialControlOleMisc)

// CSerialControlCtrl::CSerialControlCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CSerialControlCtrl ��ϵͳע�����

BOOL CSerialControlCtrl::CSerialControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SERIALCONTROL,
			IDB_SERIALCONTROL,
			afxRegApartmentThreading,
			_dwSerialControlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CSerialControlCtrl::CSerialControlCtrl - ���캯��

CSerialControlCtrl::CSerialControlCtrl()
{
	InitializeIIDs(&IID_DSerialControl, &IID_DSerialControlEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�

}

// CSerialControlCtrl::~CSerialControlCtrl - ��������

CSerialControlCtrl::~CSerialControlCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CSerialControlCtrl::OnDraw - ��ͼ����

void CSerialControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CSerialControlCtrl::DoPropExchange - �־���֧��

void CSerialControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CSerialControlCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CSerialControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CSerialControlCtrl ��Ϣ�������


void CSerialControlCtrl::SetPort(BSTR port)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	// TODO:  �ڴ���ӵ��ȴ���������
	//const std::string str = (_bstr_t)port;
	//m_serial.setPort(str);
}


LONG CSerialControlCtrl::OpenPort(BSTR port)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	SerialPort::WndHandle = GetSafeHwnd();
	return m_port.OpenPort((CString)port);
}

LONG CSerialControlCtrl::ClosePort()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//m_serial.close();
	return m_port.ClosePort();
}


LONG CSerialControlCtrl::IsOpen()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

	return m_port.IsOpen();
}


LONG CSerialControlCtrl::WritePort(BSTR data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//char* buffer = _com_util::ConvertBSTRToString(data);

	//CByteArray hexdate;
	//int len = String2Hex((CString)data, hexdate);
	//uint8_t* buffer = (uint8_t*)hexdate.GetData();
	//return m_serial.write(buffer,len);

	return m_port.WritePort((CString)data);
}

LONG CSerialControlCtrl::Available()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

	//return m_serial.available();

	return m_port.Available();
}


BSTR CSerialControlCtrl::ReadPort()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
	//int len = m_serial.available();
	//if (len > 0)
	//{
	//	strResult = m_serial.read(len).c_str();
	//}

	//return strResult.AllocSysString();

	return m_port.ReadPort().AllocSysString();
}


void CSerialControlCtrl::SetBaudRate(LONG baudrate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//m_serial.setBaudrate(baudrate);
}


void CSerialControlCtrl::SetByteSize(LONG bytesize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//m_serial.setBytesize((serial::bytesize_t)bytesize);
}


void CSerialControlCtrl::SetStopBits(LONG stopbits)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//m_serial.setStopbits((serial::stopbits_t)stopbits);
}


void CSerialControlCtrl::SetParity(LONG parity)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	//m_serial.setParity((serial::parity_t)parity);
}

//���ڽ���������Ϣ
afx_msg LRESULT CSerialControlCtrl::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	OnComm();//����ocx�¼�
	return 0;
}





