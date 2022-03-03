//-----------------------------------------------------------------------------
// 2022. 1�б� STL 3�� 3�� �����(1�� 2��)
// 
// �� �� - ���� �ڵ��� save �Լ��� save.cpp�� �и��� �� ����ǵ��� ����
// &�� �ǹ̸� ����
// class�� ����
// Youtube - Back to Basics Classic STL ���Ǹ� �� �� �ִٸ� ������ �� ����
//-----------------------------------------------------------------------------
#include <iostream>
#include "save.h"

//using namespace std;

// [����] main()�� �����ϸ� �ȵȴ�.
// �����ϸ� a�� b�� ���� ���� �ٲ����Ѵ�.

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
	//save("�ҽ�.cpp");
}

std::ostream& operator<<(std::ostream os, const Dog& dog)
{
	// TODO: ���⿡ return ���� �����մϴ�.
}

void change(Dog& a, Dog& b)
{
	Dog tmp{};	// default �ʱ�ȭ

	
}