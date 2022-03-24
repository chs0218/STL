//-----------------------------------------------------------------------------
// 2022. 1�б� STL 3�� 16�� ������(3�� 2��)
// 
// int[100] ��ſ� -> array<int, 100> �������
// int* ��ſ� -> unique_ptr<int> �������
// int*�� new int[100] ��ſ� -> unique_ptr<int[]> �������
// 
// ȣ�Ⱑ��(Callable) Ÿ�� - ������ sort�� ���
// �ڿ��� �����ϴ� Ŭ������ ����� �����ϸ鼭 - �����̳� / �ݺ��� / �˰���
// STRING
//-----------------------------------------------------------------------------
#include <iostream>
#include <thread>
#include "save.h"


using namespace std::chrono_literals;
// using namespace std;
//
// �����ų�� �Լ� �����͸� ��� �ٲ��ָ� ���� �Լ��� ȣ���ϸ鼭 �ٸ� ����� ����� �� �ִ�.
// Ű �Է��� �ٲٴ� ����� �� �� �ִ�.
//

void jump() {
	std::cout << "����" << std::endl;
}

void slide() {
	std::cout << "�����̵�" << std::endl;
}

//----
int main()
//----
{
	save("�ҽ�.cpp");
	
	void(*f)(void)= jump;

	// 3�ʿ� �ѹ��� jump/slide toggle
	int cnt{};
	while (true) {
		f();	// 1�ʸ��� ȣ��
		// 3�ʰ� ������ �ٲ۴�
		std::this_thread::sleep_for(1s);
		if ((++cnt % 3) == 0) {
			if (f == jump)
				f = slide;
			else
				f = jump;
		}
	}
}
