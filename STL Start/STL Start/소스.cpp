//-----------------------------------------------------------------------------
// 2022. 1�б� STL 6�� 2�� �����(13�� 2��)
// 
// C++20 ��� 4���� �ٽ�
//  concepts
//	range/view
//  coroutine
//  module
// 
// 6/15(��) - 15�� 1�� �⸻����
// 6/16(��) - ���� ����
//-----------------------------------------------------------------------------

#include <iostream>
#include <ranges>
#include <algorithm>
#include "save.h"
#include "STRING.h"


//---------
int main()
//---------
{
	//save("�ҽ�.cpp");
	int a[]{ 1,2,3,4,5,6,7,8,9,10 };
	
	// [����] ��� �ڿ������� Ȧ���� �����Ͽ� �Ųٷ� ����϶�
	auto Ȧ�� = [](int n) { return n % 2; };
	auto ���� = [](int n) {return n * n; };

	for (float n : std::views::iota(1) 
					| std::views::filter(Ȧ��)
					| std::views::transform(����))
		std::cout << n << " ";
	std::cout << std::endl;
}