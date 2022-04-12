//-----------------------------------------------------------------------------
// 2022. 1�б� STL 4�� 7�� �����(6�� 1��)
// 
//	�����̳�
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
//			array		-	�����ϰ� ���Ұ��� ����
//			vector		-	��� �˾ƺ� ��ġ�� �ִ� �����̳�
//			deque		-
//			foward_list	-
//			list		-
// lexicographical comparison
// ����: �ְ����� 4.27(��) (8�� 2��)
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool ����;


//----
int main()
//----
{
	// save("�ҽ�.cpp");

	// [����] "�ҽ�.cpp"�� �о� �����ڰ����� ���� ���� ���İ� ���� ���
	// ��ҹ��ڴ� �������� �ʴ´�.

	// [a] - 10
	// [b] - 3
	// [z] - 1

	std::ifstream in{ "�ҽ�.cpp" };
	std::vector<char> v{ std::istreambuf_iterator{ in }, {}};
	std::map<char, int> alphamap;

	for (auto i : v)
	{
		i = tolower(i);
		if ('a' <= i && 'z' >= i)
		{
			alphamap[i] = alphamap[i] + 1;
		}
	}

	for (auto i : alphamap)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}
