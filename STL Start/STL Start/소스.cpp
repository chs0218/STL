//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 3일 목요일(1주 2일)
// 
// 할 일 - 어제 코딩한 save 함수를 save.cpp로 분리한 후 실행되도록 수정
// &의 의미를 복습
// class를 복습
// Youtube - Back to Basics Classic STL 강의를 볼 수 있다면 도움이 될 것임
//-----------------------------------------------------------------------------
#include <iostream>
#include "save.h"

//using namespace std;

// [문제] main()을 변경하면 안된다.
// 실행하면 a와 b의 값이 서로 바뀌어야한다.

class Dog {
	friend std::ostream& operator<<(std::ostream os, const Dog& dog);
private:
	int age;
public:
	Dog() = default;

	Dog(int i) :age{ i } {};

	void changeAge(const int i)
	{
		age = i;
	}

	/*operator int() {
		return age;
	}*/

};

void change(Dog&, Dog&);

std::ostream& operator <<(std::ostream& os, const Dog& dog)
{
	os << dog.age;
	return os;
};

int main()
{
	Dog a{ 1 };
	Dog b{ 2 };

	change(a, b);

	std::cout << a << ", " << b << std::endl;
	//save("소스.cpp");
}

std::ostream& operator<<(std::ostream os, const Dog& dog)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

void change(Dog& a, Dog& b)
{
	Dog tmp{};	// default 초기화

	
}