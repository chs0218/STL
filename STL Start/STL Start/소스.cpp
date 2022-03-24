//-----------------------------------------------------------------------------
// 2022. 1�б� STL 3�� 16�� ������(4�� 1��)
// 
// �ڿ��� �����ϴ� Ŭ������ ����� �����ϸ鼭 - �����̳� / �ݺ��� / �˰���
//	STRING 
//-----------------------------------------------------------------------------
#include <iostream>
#include "save.h"

// using namespace std;

// [����] main()�� �������� ����ǵ��� class STRING�� �ڵ��϶�.
// speacial �Լ��� ������ �����ϵ��� cout���� �޸𸮿� ������ �ڵ��Ѵ�.
// ��ü ������ ������ȣ�� ������ �Ѵ�.

class STRING {
	int id;				// ���� �� �ο�
	size_t num;
	char* data;
	static int cid;		// ��ü�� ������ �� 1 ����
public:
	STRING(const char* str) : num{ strlen(str) }, data { new char[num] } {
		memcpy(data, str, num);

		id = ++cid;
		// �����޽����� �Ѹ� ����Ѵ�.
		std::cout << "ctor [" << id << "] " << this << std::endl;
	}


	~STRING() {
		// �����޽����� �Ѹ� ����Ѵ�.
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
	STRING a{ "2022 1�б�" };
	STRING b{ "STL" };
	// STRING c = a + b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << c << std::endl;

	// save("�ҽ�.cpp");
}
