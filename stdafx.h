// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <time.h>
#include <algorithm>
#include <windows.h>
#include <string>
#include <vector>


using namespace std;

#include "Include.h"



#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


#pragma warning (disable:6031)
#pragma warning (disable:4996)

#define _CRT_SECURE_NO_WARNINGS