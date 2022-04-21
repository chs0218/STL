//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 21일 수요일(8주 1일)
// 
//	컨테이너 - 다른 객체를 저장하는 객체
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
//	
//	반복자 - 포인터를 추상화한 것
//		
//-----------------------------------------------------------------------------

#include <iostream>
#include <iterator>
#include <vector>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool 관찰;
//
//template <class Iter>
//void show(Iter)
//{
//	// concept, modeul, range => c++ 20
//	std::iterator_traits<Iter>::iterator_category c;
//	std::cout << "반복자의 종류 - " << typeid(Iter).name() << typeid(c).name() << std::endl;
//}

//----
int main()
//----
{
	//save("소스.cpp");

	// 반복자의 종류(category)를 구분하고 알아본다.
	// 반복자를 인수로 받는 함수를 만들어 어떤 종류 반복자인지 출력하도록 하자
	
	/*std::vector<int> v;
	show(1);
	show(v.begin());*/
	STRING s{ "1234567890" };

	for (char c : s)
		std::cout << c << " * ";
	std::cout << std::endl;
	
}
