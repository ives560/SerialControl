#pragma once

// SerialControlPropPage.h : CSerialControlPropPage 属性页类的声明。


// CSerialControlPropPage : 有关实现的信息，请参阅 SerialControlPropPage.cpp。

class CSerialControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSerialControlPropPage)
	DECLARE_OLECREATE_EX(CSerialControlPropPage)

// 构造函数
public:
	CSerialControlPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_SERIALCONTROL };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
public:
};

