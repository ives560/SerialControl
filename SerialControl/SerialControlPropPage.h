#pragma once

// SerialControlPropPage.h : CSerialControlPropPage ����ҳ���������


// CSerialControlPropPage : �й�ʵ�ֵ���Ϣ������� SerialControlPropPage.cpp��

class CSerialControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSerialControlPropPage)
	DECLARE_OLECREATE_EX(CSerialControlPropPage)

// ���캯��
public:
	CSerialControlPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_SERIALCONTROL };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
public:
};

