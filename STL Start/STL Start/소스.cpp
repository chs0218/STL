//-----------------------------------------------------------------------------
// 2022. 1�б� STL 4�� 27�� ������(8�� 2��)
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
//	
//	���� ����
// STRING �ݺ��ڸ� �����ϵ��� �ڵ�����.(ǥ�� �����̳ʰ� �� ���� �ִ�)
// �ݺ��ڴ� �����̳ʰ� �����ϴ� ������ Ÿ���̴�.
// STRING�� iterator�� reverse_iterator�� �����ϵ��� �Ѵ�.
// �ݺ��� adapter
// insertion operator
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"

//----
int main()
//----
{

	//save("�ҽ�.cpp");
	//std::string str{ "The quick brown fox jumps over the lazy dog" };
	STRING str{ "The quick brown fox jumps over the lazy dog" };
	// [����] ���� �ڵ尡 ����ǵ��� �ʿ��� �ڵ��� ����.
	std::sort(str.begin(), str.end());

	std::cout << str << std::endl;
}
