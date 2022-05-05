//-----------------------------------------------------------------------------
// 2022. 1학기 STL 5월 4일 목요일(10주 1일)
// 
//	컨테이너 - 다른 객체를 저장하는 객체
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
// 
// Associative Container - set, multi_set, map, multi_map
// set - 언제나 key를 compare로 정렬하고 있다. 찾기/추가/삭제가 O(log N)
//		- set의 주요 동작을 알아본다. (빨리 찾기 위한 컨테이너)
//		- 내가 만든 자료형(class Dog)을 set에 넣어 관리
//		- 중복되는 데이터를 하나로만 저장(multiset을 이용해야함)
//-----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <random>
#include "save.h"
#include "STRING.h"


std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 'a', 'z' };
std::uniform_int_distribution<int> uidN{ 1, 10000 };

class Dog {
	std::string name;
	int n;
public:
	Dog() {
		for (int i = 0; i < 10; ++i)
			name += uid(dre);
		n = uidN(dre);
	}

	void show() const {
		std::cout << name << " - " << n << std::endl;
	}
	
	std::string getName() const {
		return name;
	}

	int getN() const {
		return n;
	}
};

class 정렬기준 {
public:
	bool operator() (const Dog& a, const Dog& b) const{
		return a.getN() < b.getN();
	};
};

//----
int main()
//----
{
	// save("소스.cpp");

	std::multiset<Dog, 정렬기준> s;		// n 기준 오름차순 정렬하는 set
	for (int i = 0; i < 1000; ++i)
		s.insert(Dog{});

	for (auto i = s.cbegin(); i != s.cend(); ++i)
		i->show();

	std::cout << "셋의 원소 수 - " << s.size() << std::endl;
}
