//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 13일 수요일(6주 2일)
// 
//	컨테이너
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
//			array		-	유일하게 원소갯수 고정
//			vector		-	깊게 알아볼 가치가 있는 컨테이너
//						-	원소를 마지막 위치에 추가하는데 특화되어있다.
//			deque		-	contiguous 컨테이너가 아니다.
//			foward_list	-
//			list		-
// 중간시험 4.20(수) (7주 2일)
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool 관찰;

//----
int main()
//----
{
	// save("소스.cpp");

	// [문제] "소스.cpp"의 단어를 deque에 읽어라.
	// 오름차순 정렬하시오
	// 결과를 출력하시오

	std::ifstream in{ "소스.cpp", std::ios::binary };

	std::deque<std::string> d;

	std::string s;
	while (in >> s)
		d.push_front(s);

	std::sort(d.begin(), d.end());

	for (auto i : d)
		std::cout << i << '\t';
	std::cout << std::endl;
}
