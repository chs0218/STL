//-----------------------------------------------------------------------------
// 2022. 1�б� STL 5�� 4�� �����(10�� 1��)
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
// 
// Associative Container - set, multi_set, map, multi_map
// set - ������ key�� compare�� �����ϰ� �ִ�. ã��/�߰�/������ O(log N)
//		- set�� �ֿ� ������ �˾ƺ���. (���� ã�� ���� �����̳�)
//		- ���� ���� �ڷ���(class Dog)�� set�� �־� ����
//		- �ߺ��Ǵ� �����͸� �ϳ��θ� ����(multiset�� �̿��ؾ���)
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

class ���ı��� {
public:
	bool operator() (const Dog& a, const Dog& b) const{
		return a.getN() < b.getN();
	};
};

//----
int main()
//----
{
	// save("�ҽ�.cpp");

	std::multiset<Dog, ���ı���> s;		// n ���� �������� �����ϴ� set
	for (int i = 0; i < 1000; ++i)
		s.insert(Dog{});

	for (auto i = s.cbegin(); i != s.cend(); ++i)
		i->show();

	std::cout << "���� ���� �� - " << s.size() << std::endl;
}
