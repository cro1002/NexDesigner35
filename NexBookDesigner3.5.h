
// NexBookDesigner3.5.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CNexBookDesigner35App:
// �� Ŭ������ ������ ���ؼ��� NexBookDesigner3.5.cpp�� �����Ͻʽÿ�.
//

class CNexBookDesigner35App : public CWinApp
{
public:
	CNexBookDesigner35App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CNexBookDesigner35App theApp;