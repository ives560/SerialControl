// SerialControlPropPage.cpp : CSerialControlPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "SerialControl.h"
#include "SerialControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSerialControlPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CSerialControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CSerialControlPropPage, "SERIALCONTROL.SerialControlPropPage.1",
	0x1ee9d564, 0x6d5a, 0x4b5f, 0x9d, 0x2a, 0xe8, 0xad, 0x5, 0xab, 0x33, 0xa5)

// CSerialControlPropPage::CSerialControlPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CSerialControlPropPage ��ϵͳע�����

BOOL CSerialControlPropPage::CSerialControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SERIALCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSerialControlPropPage::CSerialControlPropPage - ���캯��

CSerialControlPropPage::CSerialControlPropPage() :
	COlePropertyPage(IDD, IDS_SERIALCONTROL_PPG_CAPTION)
{

}

// CSerialControlPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CSerialControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSerialControlPropPage ��Ϣ�������
