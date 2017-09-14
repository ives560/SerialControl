

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Sep 14 18:23:57 2017
 */
/* Compiler settings for SerialControl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_SerialControlLib,0x28B5EA74,0xA67E,0x47CF,0xB0,0xF0,0xF5,0x10,0x0F,0xE8,0x13,0x4E);


MIDL_DEFINE_GUID(IID, DIID__DSerialControl,0x83F42EEB,0x9C7D,0x4745,0xB1,0xD6,0xC9,0xE5,0x3A,0xFB,0xEF,0xD1);


MIDL_DEFINE_GUID(IID, DIID__DSerialControlEvents,0xD3CF1561,0xAB30,0x427F,0xA0,0xA9,0x6A,0xF1,0x9D,0x28,0xD4,0x49);


MIDL_DEFINE_GUID(CLSID, CLSID_SerialControl,0x436434F0,0xF9B7,0x4F57,0x82,0x5A,0xA2,0xFB,0xAC,0x86,0x0E,0x7E);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



