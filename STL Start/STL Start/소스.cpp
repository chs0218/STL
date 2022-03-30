//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 16일 수요일(4주 2일)
// 
// 자원을 관리하는 클래스를 만들어 관찰하면서 - 컨테이너 / 반복자 / 알고리즘
//	STRING.h, STRING.cpp로 작성
// RVO(Return value optimization), Copy Ellision
//-----------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "STRING.h"

// using namespace std;
extern bool 관찰;

// 컨체이너 => Containers are objects that store other objects
// [문제] a를 글자순 기준 오름차순으로 정렬한 후 출력 

//----
int main()
//----
{
	관찰 = true;
	// save("소스.cpp");
	std::array<STRING, 3> a{ "2022년", "3월", "30일" };
	std::sort(a.begin(), a.end(), [](const STRING& a, const STRING& b) {
		return a.getNum() < b.getNum(); 
	});
	for (STRING& x : a)
		std::cout << x << std::endl;
}	
