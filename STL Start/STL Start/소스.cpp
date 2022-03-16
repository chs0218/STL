//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 16일 수요일(2주 2일)
// 
// 책/구글 꼭 찾아보기
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include "save.h"

//using namespace std;

// [문제] 사용자가 원하는 만큼 int를 저장할 메모리를 확보하고
// 1부터 증가하는 정수로 메모리를 채워라
// 전체 합계를 출력하라
// 예) 10
//	   1 2 3 4 5 6 7 8 9 10
//	   55
 
//----
int main()
//----
{
	int num;
	std::cout << "int 몇 개를 원하십니까? ";
	std::cin >> num;

	std::vector<int> arr;
	int result = 0;
	for (int i = 0; i < num; ++i)
	{
		arr.emplace_back(i + 1);
		result += arr[i];
	}

	std::cout << "결과: " << result << std::endl;

	// 여기 들어갈 코드를 답지에 적어라
	
	// save("소스.cpp");
}
