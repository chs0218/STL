//-----------------------------------------------------------------------------
// 2022. 1�б� STL 4�� 28�� �����(9�� 1��)
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
// 
// �ݺ��ڸ� �����ߴٸ� ���׸� �Լ��� ����� �� �� �ְڴ�
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "save.h"
#include "STRING.h"

template <class T, class Ty>
T my_find(T begin, T end, Ty target);

template <class T, class Ty>
T my_find(T begin, T end, Ty target)
{
	// While ������ ����
	for (T& i = begin; i != end; ++i)
		if (*i == target)
			return i;
	return end;
}

//----
int main()
//----
{
	// save("�ҽ�.cpp");
	STRING s{"Hello, world"};
	
	// [����] s�� � ���ڰ� ���° �������.
	while (true)
	{
		std::cout << "ã������ ���ڴ�? :";
		char c;
		std::cin >> c;
		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			std::cout << std::distance(s.begin(), p) + 1 << "��° �����Դϴ�." << std::endl;
		else
			std::cout << c << "�� ���� �����Դϴ�." << std::endl;
	}
}
