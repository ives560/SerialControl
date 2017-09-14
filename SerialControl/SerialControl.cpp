// SerialControl.cpp : CSerialControlApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "SerialControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CSerialControlApp theApp;

const GUID CDECL _tlid = { 0x28B5EA74, 0xA67E, 0x47CF, { 0xB0, 0xF0, 0xF5, 0x10, 0xF, 0xE8, 0x13, 0x4E } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CSerialControlApp::InitInstance - DLL ��ʼ��

BOOL CSerialControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CSerialControlApp::ExitInstance - DLL ��ֹ

int CSerialControlApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
