//-----------------------------------------------------------------------------
// 2022. 1�б� STL 3�� 16�� ������(4�� 2��)
// 
// �ڿ��� �����ϴ� Ŭ������ ����� �����ϸ鼭 - �����̳� / �ݺ��� / �˰���
//	STRING.h, STRING.cpp�� �ۼ�
// RVO(Return value optimization), Copy Ellision
//-----------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "STRING.h"

// using namespace std;
extern bool ����;

// ��ü�̳� => Containers are objects that store other objects
// [����] a�� ���ڼ� ���� ������������ ������ �� ��� 

//----
int main()
//----
{
	���� = true;
	// save("�ҽ�.cpp");
	std::array<STRING, 3> a{ "2022��", "3��", "30��" };
	std::sort(a.begin(), a.end(), [](const STRING& a, const STRING& b) {
		return a.getNum() < b.getNum(); 
	});
	for (STRING& x : a)
		std::cout << x << std::endl;
}	
