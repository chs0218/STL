//-----------------------------------------------------------------------------
// 2022. 1�б� STL 6�� 14�� ȭ����(?�� ?��)
// 
// ���� ����
//	�����̳�
//		Sequence		-	������ ������ ���� �а� ���ų� �߰��� �� �ִ�.
//			array		-	�����ϰ� ���Ұ��� ����
//			vector		-	��� �˾ƺ� ��ġ�� �ִ� �����̳�
//						-	���Ҹ� ������ ��ġ�� �߰��ϴµ� Ưȭ�Ǿ��ִ�.
//						-	random access
//			deque		-	contiguous �����̳ʰ� �ƴϴ�.
//						-	������ ��ġ �߰� ����
//						-	�ݺ��� ��ȿȭ ����
//						-	random access ����(������ ��¦ ����)
//			foward_list	-	single linked list
//			list		-	������ ��ġ���� ���԰� ������ O(1)
// 
// Associative Container - set, multi_set, map, multi_map
// 
// set - ������ key�� compare�� �����ϰ� �ִ�. ã��/�߰�/������ O(log N)
//		- set�� �ֿ� ������ �˾ƺ���. (���� ã�� ���� �����̳�)
//		- ���� ���� �ڷ���(class Dog)�� set�� �־� ����
//		- �ߺ��Ǵ� �����͸� �ϳ��θ� ����(multiset�� �̿��ؾ���)
// 
// Sequential - array, vector, deque, forwawrd_list, list
// Associative Container - set, multi_set, map, multi_map
// Unordered Associative - unordered_set, unordered_multiset, unordered_map
//							unoredered_multimap
// 
// map<key, value, key_compare>
//		- �����迭(associative array)�� ����� �� �ִ�.
// 
// �˰���
// - non-modifying sequence operations (���Ҹ� �������� �ʴ� �˰���)
// - modifying sequence operations
// - sorting operations
// - partition
// 
// �˰��� - �и� / ���� ���� �Լ���
//		partition
//		nth_element
//		partial_sort
//		stable_sort
//-----------------------------------------------------------------------------

#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
#include "save.h"
#include "STRING.h"

// ���� ������ �޸�
std::array<int, 1000'0000> numbers;

// �����̳ʿ� �ִ��� ã�ƺ� int ����
std::array<int, 3000> toFind;

std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 1, 1'0000'0000 };

//---------
int main()
//---------
{
	//save("�ҽ�.cpp");
	// random int
	for (int& n : numbers)
		n = uid(dre);

	// ã�ƾ��� int
	for (int& n : toFind)
		n = uid(dre);


	{	// ������ ã�� �Ƿ��� �˾ƺ���.
		std::vector<int> v{ numbers.begin(), numbers.end() };

		std::cout << "������ ���� �� - " << v.size() << std::endl;

		// �ð� ��� ����
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			auto p = std::find(v.begin(), v.end(), n);
			if (p != v.end())
				cnt++;
		}
		auto stop = std::chrono::steady_clock::now();
		// �ð� ��� ��

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "�ɸ� �ð� O(n) - " << et << "��s" << std::endl;
		std::cout << "ã�ƾ� �� int ���� - " << toFind.size() << std::endl;
		std::cout << "��ó���� ã�� ���� - " << cnt << std::endl << std::endl;
	}

	{	// ���ĵ� ������ ã�� �Ƿ��� �˾ƺ���.
		std::vector<int> v{ numbers.begin(), numbers.end() };
		std::sort(v.begin(), v.end());
		std::cout << "���ĵ� ������ ���� �� - " << v.size() << std::endl;

		// �ð� ��� ����
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (std::binary_search(v.begin(), v.end(), n))
				cnt++;
		}
		auto stop = std::chrono::steady_clock::now();
		// �ð� ��� ��

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "�ɸ� �ð� O(log n) - " << et << "��s" << std::endl;
		std::cout << "ã�ƾ� �� int ���� - " << toFind.size() << std::endl;
		std::cout << "���ĵ� ��ó���� ã�� ���� - " << cnt << std::endl << std::endl;
	}

	{	// ���� ã�� �Ƿ��� �˾ƺ���.
		std::set<int> s{ numbers.begin(), numbers.end() };

		std::cout << "���� ���� �� - " << s.size() << std::endl;

		// �ð� ��� ����
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (s.contains(n))
				++cnt;
		}
		auto stop = std::chrono::steady_clock::now();
		// �ð� ��� ��

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "�ɸ� �ð� O(log n) - " << et << "��s" << std::endl;
		std::cout << "ã�ƾ� �� int ���� - " << toFind.size() << std::endl;
		std::cout << "�¿��� ã�� ���� - " << cnt << std::endl << std::endl;
	}

	{	// ���������� ã�� �Ƿ��� �˾ƺ���.
		std::unordered_set<int> us{ numbers.begin(), numbers.end() };

		std::cout << "���������� ���� �� - " << us.size() << std::endl;

		// �ð� ��� ����
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (us.contains(n))
				++cnt;
		}
		auto stop = std::chrono::steady_clock::now();
		// �ð� ��� ��

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "�ɸ� �ð� O(1) - " << et << "��s" << std::endl;
		std::cout << "ã�ƾ� �� int ���� - " << toFind.size() << std::endl;
		std::cout << "�������¿��� ã�� ���� - " << cnt << std::endl << std::endl;
	}
}