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
#include "save.h"
#include "STRING.h"

//---------
int main()
//---------
{
	//save("소스.cpp");

	std::cout << "기말시험" << std::endl;
}