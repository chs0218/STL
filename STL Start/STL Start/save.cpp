//-----------------------------------------------------------------------------
// Save.cpp
// 
// 이 함수를 호출하면 "2022년 1학기 STL 수78목23 강의저장.txt"에
// 전달된 이름의 파일을 읽어 덧붙인다.
// 
// 2022.3.3	Programmed by HS
//-----------------------------------------------------------------------------


#include <filesystem>
#include <fstream>
#include <vector>
#include <chrono>	// 시간 관련 함수
#include <algorithm>
#include <cmath>	// floor
#include "save.h"

void save(std::string_view fname)
{
	// 읽을 파일을 연다 - RALL
	std::ifstream in{ fname.data() };


	// 쓸 파일도 연다
	std::ofstream out{ "2022년 1학기 STL 수 78목23 강의저장.txt", std::ios::app };


	// 저장할 파일이름과 크기(C++17)를 출력한다.
	out << std::endl << std::endl;
	out << "파일이름: " << fname << std::endl;
	out << "파일크기: " << std::filesystem::file_size(fname) << std::endl;
	

	// 현재 날짜와 시간(C++20)을 출력한다.
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << "저장시간: " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;


	// 읽은 파일을 강의저장 파일에 덧붙인다.
	// 1. 벡터에 파일을 읽어온다.
	out << std::endl;

	// std::vector<char> v{ std::istream_iterator<char>{in}, {} };

	// 1. 벡터에 파일을 읽어온다 - 컨테이너(자료구조)
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };		// 띄어쓰기도 포함해서 저장

	/*for (char c : v)
		out << c;*/

	// 2. copy 알고리즘으로 벡터에 있는 글자를 강의저장파일로 복사한다
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}