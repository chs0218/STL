//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 27일 수요일(8주 2일)
// 
//	컨테이너 - 다른 객체를 저장하는 객체
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
//	
//	오늘 할일
// STRING 반복자를 제공하도록 코딩하자.(표준 컨테이너가 될 수도 있다)
// 반복자는 컨테이너가 제공하는 데이터 타입이다.
// STRING이 iterator와 reverse_iterator를 제공하도록 한다.
// 반복자 adapter
// insertion operator
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"

//----
int main()
//----
{

	//save("소스.cpp");
	//std::string str{ "The quick brown fox jumps over the lazy dog" };
	STRING str{ "The quick brown fox jumps over the lazy dog" };
	// [도전] 다음 코드가 실행되도록 필요한 코딩을 하자.
	std::sort(str.begin(), str.end());

	std::cout << str << std::endl;
}
