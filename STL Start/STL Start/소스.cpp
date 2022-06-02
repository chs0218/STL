//-----------------------------------------------------------------------------
// 2022. 1학기 STL 6월 2일 목요일(13주 2일)
// 
// C++20 언어 4가지 핵심
//  concepts
//	range/view
//  coroutine
//  module
// 
// 6/15(수) - 15주 1일 기말시험
// 6/16(목) - 강의 정리
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
	//save("소스.cpp");
	int a[]{ 1,2,3,4,5,6,7,8,9,10 };
	
	// [문제] 모든 자연수에서 홀수만 제곱하여 거꾸로 출력하라
	auto 홀수 = [](int n) { return n % 2; };
	auto 제곱 = [](int n) {return n * n; };

	for (float n : std::views::iota(1) 
					| std::views::filter(홀수)
					| std::views::transform(제곱))
		std::cout << n << " ";
	std::cout << std::endl;
}