//-----------------------------------------------------------------------------
// 2022. 1학기 STL 4월 6일 수요일(5주 2일)
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
#include <vector>
#include "save.h"
#include "STRING.h"

// using namespace std;
extern bool 관찰;


//----
int main()
//----
{
	// 스택에 생성되었다가 삭제되고 복사생성으로 힙에 생성?
	// 임시객체를 만들었다가 깊은 복사로 힙에 생성한 뒤 포인터로 가르킴
	// RAII를통해 스택 객체가 삭제됨
	
	//save("소스.cpp");
	관찰 = true;
	std::vector<STRING> v{ "1234567"};
	v.emplace_back("1234567890");

	std::cout << std::endl;

}	
