//-----------------------------------------------------------------------------
// 2022. 1학기 STL 3월 2일 수요일(1주 1일)
// 
// - 강의소개, 출석점수없음
// - 교과서, cppreference.com
// - google coding convention을 참고
// - 프로젝트 환경설정 Release/x64
//		메뉴 - 프로젝트 - 설정 - C++언어: 최신언어초안
// - 공부란 무엇인가?
// 할 일 - 한학기 코딩한 내용을 저장할 수 있게 save 기능 완성
//-----------------------------------------------------------------------------
#include <iostream>
#include <string_view>
#include <filesystem>
#include <chrono>	// 시간 관련 함수
#include <fstream>
#include <vector>
#include <algorithm>

//using namespace std;
//void save(const string&);
void save(std::string_view);

int main()
{
	// string과 string_view 크기 확인
	
	std::cout << "string 크기:"<< sizeof(std::string) << std::endl;
	std::cout << "string_view 크기:"<< sizeof(std::string_view) << std::endl;
	save("소스.cpp");
}

void save(std::string_view fname)
{
	// 읽을 파일을 연다
	std::ifstream in{ fname.data() };


	// 쓸 파일도 연다
	std::ofstream out{ "2022년 1학기 STL 수 78목23 강의저장.txt", std::ios::app };


	// 저장할 파일이름과 크기(C++17)를 출력한다.
	out << std::endl << std::endl;
	out << "파일이름: " << fname << std::endl;
	out << "파일크기: " << std::filesystem::file_size(fname) << std::endl;
	

	// 현재 날짜와 시간(C++20)을 출력한다.
	out << std::endl << std::endl;
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << "저장시간: " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;
	

	// 읽은 파일을 강의저장 파일에 덧붙인다.
	// 1. 벡터에 파일을 읽어온다.
	out << std::endl << std::endl;

	// std::vector<char> v{ std::istream_iterator<char>{in}, {} };
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };		// 띄어쓰기도 포함해서 저장
	
	/*for (char c : v)
		out << c;*/

	// 2. copy 알고리즘으로 벡터에 있는 글자를 강의저장파일로 복사한다
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}