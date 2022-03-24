//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 16일 수요일(4주 1일)
// 
// 자원을 관리하는 클래스를 만들어 관찰하면서 - 컨테이너 / 반복자 / 알고리즘
//	STRING 
//-----------------------------------------------------------------------------
#include <iostream>
#include "save.h"

// using namespace std;

// [문제] main()이 문제없이 실행되도록 class STRING을 코딩하라.
// speacial 함수는 동작을 관찰하도록 cout으로 메모리와 동작을 코딩한다.
// 객체 생성시 고유번호를 갖도록 한다.

class STRING {
	int id;				// 생성 시 부여
	size_t num;
	char* data;
	static int cid;		// 객체가 생성될 때 1 증가
public:
	STRING(const char* str) : num{ strlen(str) }, data { new char[num] } {
		memcpy(data, str, num);

		id = ++cid;
		// 관찰메시지를 켜면 출력한다.
		std::cout << "ctor [" << id << "] " << this << std::endl;
	}


	~STRING() {
		// 관찰메시지를 켜면 출력한다.
		std::cout << "dtor [" << id << "] " << this << std::endl;
		delete[] data;
	}

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};


int STRING::cid{};
std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.data[i];

	return os;
}


//----
int main()
//----
{
	std::cout << sizeof(STRING) << std::endl;
	STRING a{ "2022 1학기" };
	STRING b{ "STL" };
	// STRING c = a + b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << c << std::endl;

	// save("소스.cpp");
}
