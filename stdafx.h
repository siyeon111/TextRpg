// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
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