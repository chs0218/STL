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
#include <list>
#include <vector>
#include <ranges>
#include "save.h"
#include "STRING.h"


// 벡터가 단어 쌍을 저장할 수 있도록 한다.
// first는 정렬하고 second는 원래 단어를 저장

struct WP : public std::pair<std::string, std::string> {
	WP(const std::string& s) : std::pair<std::string, std::string>{ s,s } {
		std::sort(first.begin(), first.end());
	}
};

//---------
int main()
//---------
{
	// save("소스.cpp");
	// [문제] "단어들.txt"에 있는 단어를 읽고 갯수를 출력하라.
		
	std::ifstream in{ "단어들.txt" };

	// std::string의 operator <<가 오버로딩 되어있기 때문에 사용가능
	std::vector<WP> v{ std::istream_iterator<std::string> {in}, {} };
	std::cout << "단어의 개수 - " << v.size() << std::endl;
	
	// v에 저장된 WP를 출력해본다.
	// 30000번째부터 100개를 출력하라
	/*for (auto [정렬, 원본] : v | std::views::drop(30000)
								  | std::views::take(100)) {
		std::cout << 정렬 << " ---- " << 원본 << std::endl;
	}*/

	/*std::sort(v.begin(), v.end(), [](const WP& a, const WP& b) {
		return a.first < b.first;
	});*/

	std::ranges::sort(v, {}, &WP::first);

	/*for (auto [정렬, 원본] : v | std::views::drop(30000)
		| std::views::take(100)) {
		std::cout << 정렬 << " ---- " << 원본 << std::endl;
	}*/

	// [문제] 모든 anagram을 출력하라.
	auto b = v.begin();
	int cnt{};
	//std::ofstream out{"애너그램들.txt"};
	
	std::vector<std::list<std::string>> vv;
	vv.reserve(31000);

	// [문제] 애너그램 쌍이 가장 많은 것을 찾아라
	while (true) {
		auto i = std::adjacent_find(b, v.end(), [](const WP& a, const WP& b) {
			return a.first == b.first;
		});

		if (i == v.end())
			break;

		auto j = std::find_if_not(i + 1, v.end(), [i](const WP& a) {
			return a.first == i->first;
		});

		// [i, j]는 애너그램 구간이다.
		std::list<std::string> cont;
		for (auto p = i; p < j; ++p)
			cont.push_back(p->second);
		vv.push_back(cont);
		b = j;
	}

	// vv를 list의 갯수 순으로 내림차순 정렬
	std::sort(vv.begin(), vv.end(), [](const std::list<std::string>& a, const std::list<std::string>& b) {
		return a.size() > b.size();
	});

	std::cout << "애너그램 많은 수 - " << vv.begin()->size() << std::endl;

	for (const std::list<std::string>& cont : vv | std::views::take(10))
	{
		for (const std::string s : cont)
			std::cout << s << " ";
		std::cout << std::endl;
	}

}