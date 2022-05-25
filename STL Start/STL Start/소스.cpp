//-----------------------------------------------------------------------------
// 2022. 1�б� STL 5�� 25�� �����(12�� 2��)
// 
// �˰��� - �и� / ���� ���� �Լ���
//		partition
//		nth_element
//		partial_sort
//		stable_sort
// 
// ���⵵ Ȯ���ؾ���
// 6/15(��) - 15�� 1�� �⸻����
// 6/16(��) - ���� ����
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "save.h"
#include "STRING.h"

//
// using namespace std;
//

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution uid{ 1, 9};
struct Dog
{
	int num1;
	int num2;

	Dog() {
		num1 = uid(dre);
		num2 = uid(dre);
	}

};

//----
int main()
//----
{
	// save("�ҽ�.cpp");
	std::vector<Dog> dogs(100);	//Dog{} 20�� ȣ��
	// num1���� �������� ����
	std::sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.num1 < b.num1; });
	std::sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.num2 < b.num2; });
	for (Dog dog : dogs)
		std::cout << dog.num1 << " - " << dog.num2 << std::endl;
	// num2���� �������� ����

}