//-----------------------------------------------------------------------------
// 2022. 1�б� STL 4�� 13�� ������(6�� 2��)
// 
//	�����̳�
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
//			array		-	�����ϰ� ���Ұ��� ����
//			vector		-	��� �˾ƺ� ��ġ�� �ִ� �����̳�
//						-	���Ҹ� ������ ��ġ�� �߰��ϴµ� Ưȭ�Ǿ��ִ�.
//			deque		-	contiguous �����̳ʰ� �ƴϴ�.
//			foward_list	-
//			list		-
// �߰����� 4.20(��) (7�� 2��)
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool ����;

//----
int main()
//----
{
	// save("�ҽ�.cpp");

	// [����] "�ҽ�.cpp"�� �ܾ deque�� �о��.
	// �������� �����Ͻÿ�
	// ����� ����Ͻÿ�

	std::ifstream in{ "�ҽ�.cpp", std::ios::binary };

	std::deque<std::string> d;

	std::string s;
	while (in >> s)
		d.push_front(s);

	std::sort(d.begin(), d.end());

	for (auto i : d)
		std::cout << i << '\t';
	std::cout << std::endl;
}
