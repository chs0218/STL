//-----------------------------------------------------------------------------
// 2022. 1학기 STL 6월 2일 목요일(14주 1일)
// 
// 14주 anagram 단어들.txt를 다운받아 코딩한다
// 6/15(수) - 15주 1일 기말시험
// 6/16(목) - 강의 정리
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "STRING.h"

//---------
int main()
//---------
{
	//save("소스.cpp");
	// [문제] "단어들.txt"에 있는 단어를 읽고 갯수를 출력하라.
		
	std::ifstream in{ "단어들.txt" };

	// std::string의 operator <<가 오버로딩 되어있기 때문에 사용가능
	std::vector<std::string> word{ std::istream_iterator<std::string> {in}, {} };
	std::cout << word.size() << std::endl;

	// 정렬되어 있나 확인해보자

	// 세번째 인자로 ? 기준으로 정렬되어있나 확인해보자!
	std::cout << "정렬? "<< std::boolalpha << std::is_sorted(word.begin(), word.end(), std::less<std::string>()) << std::endl;

	// 중복이 있나 체크해보자!
	auto p = std::unique(word.begin(), word.end());
	if (p == word.end())
		std::cout << "중복X" << std::endl;
	else
		std::cout << "중복O" << std::endl;

	// [문제] 가장 긴 단어를 출력하라.
	p = std::max_element(word.begin(), word.end(), [](const std::string& a, const std::string& b) {
		return a.size() < b.size();  
	});
	std::cout << "길이 " <<  p->size() << ", " << *p << std::endl;


	// [과제] 사용자 입력한 단어가 단어들에 있는지 확인한다.
	// 있다면 anagram을 찾아 화면에 출력하라.
	while (true){
		std::string s;
		std::cout << "찾을 단어는? ";
		std::cin >> s;
		
		if (!std::binary_search(word.begin(), word.end(), s)) {
			std::cout << "단어가 없습니다." << std::endl;
			continue;
		}

		// 애너그램을 찾아 출력한다.
		// word의 각 순열이 단어들에 있는지 확인한다.
		
		
	}
}