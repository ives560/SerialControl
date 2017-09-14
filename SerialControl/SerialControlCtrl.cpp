// SerialControlCtrl.cpp : CSerialControlCtrl ActiveX 控件类的实现。

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

// 消息映射

BEGIN_MESSAGE_MAP(CSerialControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
ON_MESSAGE(COM_RECVDATA, &CSerialControlCtrl::OnRecvData)
END_MESSAGE_MAP()

// 调度映射

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

// 事件映射

BEGIN_EVENT_MAP(CSerialControlCtrl, COleControl)
	EVENT_CUSTOM_ID("OnComm", eventidOnComm, OnComm, VTS_NONE)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CSerialControlCtrl, 1)
	PROPPAGEID(CSerialControlPropPage::guid)
END_PROPPAGEIDS(CSerialControlCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CSerialControlCtrl, "SERIALCONTROL.SerialControlCtrl.1",
	0x436434f0, 0xf9b7, 0x4f57, 0x82, 0x5a, 0xa2, 0xfb, 0xac, 0x86, 0xe, 0x7e)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CSerialControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DSerialControl = { 0x83F42EEB, 0x9C7D, 0x4745, { 0xB1, 0xD6, 0xC9, 0xE5, 0x3A, 0xFB, 0xEF, 0xD1 } };
const IID IID_DSerialControlEvents = { 0xD3CF1561, 0xAB30, 0x427F, { 0xA0, 0xA9, 0x6A, 0xF1, 0x9D, 0x28, 0xD4, 0x49 } };

// 控件类型信息

static const DWORD _dwSerialControlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSerialControlCtrl, IDS_SERIALCONTROL, _dwSerialControlOleMisc)

// CSerialControlCtrl::CSerialControlCtrlFactory::UpdateRegistry -
// 添加或移除 CSerialControlCtrl 的系统注册表项

BOOL CSerialControlCtrl::CSerialControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CSerialControlCtrl::CSerialControlCtrl - 构造函数

CSerialControlCtrl::CSerialControlCtrl()
{
	InitializeIIDs(&IID_DSerialControl, &IID_DSerialControlEvents);
	// TODO:  在此初始化控件的实例数据。

}

// CSerialControlCtrl::~CSerialControlCtrl - 析构函数

CSerialControlCtrl::~CSerialControlCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CSerialControlCtrl::OnDraw - 绘图函数

void CSerialControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CSerialControlCtrl::DoPropExchange - 持久性支持

void CSerialControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CSerialControlCtrl::OnResetState - 将控件重置为默认状态

void CSerialControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CSerialControlCtrl 消息处理程序


void CSerialControlCtrl::SetPort(BSTR port)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	// TODO:  在此添加调度处理程序代码
	//const std::string str = (_bstr_t)port;
	//m_serial.setPort(str);
}


LONG CSerialControlCtrl::OpenPort(BSTR port)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	SerialPort::WndHandle = GetSafeHwnd();
	return m_port.OpenPort((CString)port);
}

LONG CSerialControlCtrl::ClosePort()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	//m_serial.close();
	return m_port.ClosePort();
}


LONG CSerialControlCtrl::IsOpen()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码

	return m_port.IsOpen();
}


LONG CSerialControlCtrl::WritePort(BSTR data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
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

	// TODO:  在此添加调度处理程序代码

	//return m_serial.available();

	return m_port.Available();
}


BSTR CSerialControlCtrl::ReadPort()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//CString strResult;

	// TODO:  在此添加调度处理程序代码
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

	// TODO:  在此添加调度处理程序代码
	//m_serial.setBaudrate(baudrate);
}


void CSerialControlCtrl::SetByteSize(LONG bytesize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	//m_serial.setBytesize((serial::bytesize_t)bytesize);
}


void CSerialControlCtrl::SetStopBits(LONG stopbits)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	//m_serial.setStopbits((serial::stopbits_t)stopbits);
}


void CSerialControlCtrl::SetParity(LONG parity)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	//m_serial.setParity((serial::parity_t)parity);
}

//串口接收数据消息
afx_msg LRESULT CSerialControlCtrl::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	OnComm();//触发ocx事件
	return 0;
}





