//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 28일 목요일(9주 1일)
// 
//	컨테이너 - 다른 객체를 저장하는 객체
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
// 
// 반복자를 이해했다면 제네릭 함수를 만들어 볼 수 있겠다
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "save.h"
#include "STRING.h"

template <class T, class Ty>
T my_find(T begin, T end, Ty target);

template <class T, class Ty>
T my_find(T begin, T end, Ty target)
{
	// While 문으로 쓰기
	for (T& i = begin; i != end; ++i)
		if (*i == target)
			return i;
	return end;
}

//----
int main()
//----
{
	// save("소스.cpp");
	STRING s{"Hello, world"};
	
	// [문제] s에 어떤 문자가 몇번째 출력하자.
	while (true)
	{
		std::cout << "찾으려는 문자는? :";
		char c;
		std::cin >> c;
		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			std::cout << std::distance(s.begin(), p) + 1 << "번째 문자입니다." << std::endl;
		else
			std::cout << c << "는 없는 문자입니다." << std::endl;
	}
}
