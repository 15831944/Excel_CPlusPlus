
// Excel_C++.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExcel_CApp: 
// �йش����ʵ�֣������ Excel_C++.cpp
//

class CExcel_CApp : public CWinApp
{
public:
	CExcel_CApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExcel_CApp theApp;