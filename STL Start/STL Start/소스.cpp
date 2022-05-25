//-----------------------------------------------------------------------------
// 2022. 1학기 STL 5월 25일 목요일(12주 2일)
// 
// 알고리즘 - 분리 / 정렬 관련 함수들
//		partition
//		nth_element
//		partial_sort
//		stable_sort
// 
// 복잡도 확인해야함
// 6/15(수) - 15주 1일 기말시험
// 6/16(목) - 강의 정리
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "save.h"
#include "STRING.h"

//
// using namespace std;
//

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution uid{ 1, 9};
struct Dog
{
	int num1;
	int num2;

	Dog() {
		num1 = uid(dre);
		num2 = uid(dre);
	}

};

//----
int main()
//----
{
	// save("소스.cpp");
	std::vector<Dog> dogs(100);	//Dog{} 20번 호출
	// num1기준 오름차순 정렬
	std::sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.num1 < b.num1; });
	std::sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.num2 < b.num2; });
	for (Dog dog : dogs)
		std::cout << dog.num1 << " - " << dog.num2 << std::endl;
	// num2기준 오름차순 정렬

}