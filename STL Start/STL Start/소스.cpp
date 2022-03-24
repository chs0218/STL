//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 16일 수요일(3주 2일)
// 
// int[100] 대신에 -> array<int, 100> 사용하자
// int* 대신에 -> unique_ptr<int> 사용하자
// int*가 new int[100] 대신에 -> unique_ptr<int[]> 사용하자
// 
// 호출가능(Callable) 타입 - 예제는 sort를 사용
// 자원을 관리하는 클래스를 만들어 관찰하면서 - 컨테이너 / 반복자 / 알고리즘
// STRING
//-----------------------------------------------------------------------------
#include <iostream>
#include <thread>
#include "save.h"


using namespace std::chrono_literals;
// using namespace std;
//
// 실행시킬때 함수 포인터를 계속 바꿔주면 같은 함수를 호출하면서 다른 기능을 사용할 수 있다.
// 키 입력을 바꾸는 방법이 될 수 있다.
//

void jump() {
	std::cout << "점프" << std::endl;
}

void slide() {
	std::cout << "슬라이드" << std::endl;
}

//----
int main()
//----
{
	save("소스.cpp");
	
	void(*f)(void)= jump;

	// 3초에 한번씩 jump/slide toggle
	int cnt{};
	while (true) {
		f();	// 1초마다 호출
		// 3초가 지나면 바꾼다
		std::this_thread::sleep_for(1s);
		if ((++cnt % 3) == 0) {
			if (f == jump)
				f = slide;
			else
				f = jump;
		}
	}
}
