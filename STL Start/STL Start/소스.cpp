//-----------------------------------------------------------------------------
// 2022. 1�б� STL 4�� 21�� ������(8�� 1��)
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
//	
//	�ݺ��� - �����͸� �߻�ȭ�� ��
//		
//-----------------------------------------------------------------------------

#include <iostream>
#include <iterator>
#include <vector>
#include "save.h"
#include "STRING.h"

// using namespace std;
// extern bool ����;
//
//template <class Iter>
//void show(Iter)
//{
//	// concept, modeul, range => c++ 20
//	std::iterator_traits<Iter>::iterator_category c;
//	std::cout << "�ݺ����� ���� - " << typeid(Iter).name() << typeid(c).name() << std::endl;
//}

//----
int main()
//----
{
	//save("�ҽ�.cpp");

	// �ݺ����� ����(category)�� �����ϰ� �˾ƺ���.
	// �ݺ��ڸ� �μ��� �޴� �Լ��� ����� � ���� �ݺ������� ����ϵ��� ����
	
	/*std::vector<int> v;
	show(1);
	show(v.begin());*/
	STRING s{ "1234567890" };

	for (char c : s)
		std::cout << c << " * ";
	std::cout << std::endl;
	
}
