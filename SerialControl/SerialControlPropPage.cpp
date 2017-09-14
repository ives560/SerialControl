// SerialControlPropPage.cpp : CSerialControlPropPage 属性页类的实现。

#include "stdafx.h"
#include "SerialControl.h"
#include "SerialControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSerialControlPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CSerialControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CSerialControlPropPage, "SERIALCONTROL.SerialControlPropPage.1",
	0x1ee9d564, 0x6d5a, 0x4b5f, 0x9d, 0x2a, 0xe8, 0xad, 0x5, 0xab, 0x33, 0xa5)

// CSerialControlPropPage::CSerialControlPropPageFactory::UpdateRegistry -
// 添加或移除 CSerialControlPropPage 的系统注册表项

BOOL CSerialControlPropPage::CSerialControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SERIALCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSerialControlPropPage::CSerialControlPropPage - 构造函数

CSerialControlPropPage::CSerialControlPropPage() :
	COlePropertyPage(IDD, IDS_SERIALCONTROL_PPG_CAPTION)
{

}

// CSerialControlPropPage::DoDataExchange - 在页和属性间移动数据

void CSerialControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSerialControlPropPage 消息处理程序
