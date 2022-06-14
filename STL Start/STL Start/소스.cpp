//-----------------------------------------------------------------------------
// 2022. 1학기 STL 6월 14일 화요일(?주 ?일)
// 
// 시험 공부
//	컨테이너
//		Sequence		-	임의의 원소의 값을 읽고 쓰거나 추가할 수 있다.
//			array		-	유일하게 원소갯수 고정
//			vector		-	깊게 알아볼 가치가 있는 컨테이너
//						-	원소를 마지막 위치에 추가하는데 특화되어있다.
//						-	random access
//			deque		-	contiguous 컨테이너가 아니다.
//						-	마지막 위치 추가 삭제
//						-	반복자 무효화 없음
//						-	random access 지원(실제론 살짝 느림)
//			foward_list	-	single linked list
//			list		-	임의의 위치에서 삽입과 삭제가 O(1)
// 
// Associative Container - set, multi_set, map, multi_map
// 
// set - 언제나 key를 compare로 정렬하고 있다. 찾기/추가/삭제가 O(log N)
//		- set의 주요 동작을 알아본다. (빨리 찾기 위한 컨테이너)
//		- 내가 만든 자료형(class Dog)을 set에 넣어 관리
//		- 중복되는 데이터를 하나로만 저장(multiset을 이용해야함)
// 
// Sequential - array, vector, deque, forwawrd_list, list
// Associative Container - set, multi_set, map, multi_map
// Unordered Associative - unordered_set, unordered_multiset, unordered_map
//							unoredered_multimap
// 
// map<key, value, key_compare>
//		- 연관배열(associative array)로 사용할 수 있다.
// 
// 알고리즘
// - non-modifying sequence operations (원소를 수정하지 않는 알고리즘)
// - modifying sequence operations
// - sorting operations
// - partition
// 
// 알고리즘 - 분리 / 정렬 관련 함수들
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

// 정수 저장할 메모리
std::array<int, 1000'0000> numbers;

// 컨테이너에 있는지 찾아볼 int 값들
std::array<int, 3000> toFind;

std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 1, 1'0000'0000 };

//---------
int main()
//---------
{
	//save("소스.cpp");
	// random int
	for (int& n : numbers)
		n = uid(dre);

	// 찾아야할 int
	for (int& n : toFind)
		n = uid(dre);


	{	// 벡터의 찾기 실력을 알아본다.
		std::vector<int> v{ numbers.begin(), numbers.end() };

		std::cout << "벡터의 원소 수 - " << v.size() << std::endl;

		// 시간 재기 시작
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			auto p = std::find(v.begin(), v.end(), n);
			if (p != v.end())
				cnt++;
		}
		auto stop = std::chrono::steady_clock::now();
		// 시간 재기 끝

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "걸린 시간 O(n) - " << et << "μs" << std::endl;
		std::cout << "찾아야 할 int 개수 - " << toFind.size() << std::endl;
		std::cout << "벡처에서 찾은 개수 - " << cnt << std::endl << std::endl;
	}

	{	// 정렬된 벡터의 찾기 실력을 알아본다.
		std::vector<int> v{ numbers.begin(), numbers.end() };
		std::sort(v.begin(), v.end());
		std::cout << "정렬된 벡터의 원소 수 - " << v.size() << std::endl;

		// 시간 재기 시작
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (std::binary_search(v.begin(), v.end(), n))
				cnt++;
		}
		auto stop = std::chrono::steady_clock::now();
		// 시간 재기 끝

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "걸린 시간 O(log n) - " << et << "μs" << std::endl;
		std::cout << "찾아야 할 int 개수 - " << toFind.size() << std::endl;
		std::cout << "정렬된 벡처에서 찾은 개수 - " << cnt << std::endl << std::endl;
	}

	{	// 셋의 찾기 실력을 알아본다.
		std::set<int> s{ numbers.begin(), numbers.end() };

		std::cout << "셋의 원소 수 - " << s.size() << std::endl;

		// 시간 재기 시작
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (s.contains(n))
				++cnt;
		}
		auto stop = std::chrono::steady_clock::now();
		// 시간 재기 끝

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "걸린 시간 O(log n) - " << et << "μs" << std::endl;
		std::cout << "찾아야 할 int 개수 - " << toFind.size() << std::endl;
		std::cout << "셋에서 찾은 개수 - " << cnt << std::endl << std::endl;
	}

	{	// 언오더드셋의 찾기 실력을 알아본다.
		std::unordered_set<int> us{ numbers.begin(), numbers.end() };

		std::cout << "언오더드셋의 원소 수 - " << us.size() << std::endl;

		// 시간 재기 시작
		int cnt{};
		auto start = std::chrono::steady_clock::now();
		for (int n : toFind)
		{
			if (us.contains(n))
				++cnt;
		}
		auto stop = std::chrono::steady_clock::now();
		// 시간 재기 끝

		auto et = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << "걸린 시간 O(1) - " << et << "μs" << std::endl;
		std::cout << "찾아야 할 int 개수 - " << toFind.size() << std::endl;
		std::cout << "언오더드셋에서 찾은 개수 - " << cnt << std::endl << std::endl;
	}
}