//-----------------------------------------------------------------------------
// 2022. 1�б� STL 3�� 16�� ������(2�� 2��)
// 
// å/���� �� ã�ƺ���
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include "save.h"

//using namespace std;

// [����] ����ڰ� ���ϴ� ��ŭ int�� ������ �޸𸮸� Ȯ���ϰ�
// 1���� �����ϴ� ������ �޸𸮸� ä����
// ��ü �հ踦 ����϶�
// ��) 10
//	   1 2 3 4 5 6 7 8 9 10
//	   55
 
//----
int main()
//----
{
	int num;
	std::cout << "int �� ���� ���Ͻʴϱ�? ";
	std::cin >> num;

	std::vector<int> arr;
	int result = 0;
	for (int i = 0; i < num; ++i)
	{
		arr.emplace_back(i + 1);
		result += arr[i];
	}

	std::cout << "���: " << result << std::endl;

	// ���� �� �ڵ带 ������ �����
	
	// save("�ҽ�.cpp");
}
