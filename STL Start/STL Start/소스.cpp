//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 7일 목요일(6주 1일)
// 
//	컨테이너
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
//			array		-	유일하게 원소갯수 고정
//			vector		-	깊게 알아볼 가치가 있는 컨테이너
//			deque		-
//			foward_list	-
//			list		-
// lexicographical comparison
// 예정: 주간시험 4.27(수) (8주 2일)
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool 관찰;


//----
int main()
//----
{
	// save("소스.cpp");

	// [문제] "소스.cpp"을 읽어 영문자갯수를 세서 다음 형식과 같이 출력
	// 대소문자는 구분하지 않는다.

	// [a] - 10
	// [b] - 3
	// [z] - 1

	std::ifstream in{ "소스.cpp" };
	std::vector<char> v{ std::istreambuf_iterator{ in }, {}};
	std::map<char, int> alphamap;

	for (auto i : v)
	{
		i = tolower(i);
		if ('a' <= i && 'z' >= i)
		{
			alphamap[i] = alphamap[i] + 1;
		}
	}

	for (auto i : alphamap)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}
