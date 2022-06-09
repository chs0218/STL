//-----------------------------------------------------------------------------
// 2022. 1�б� STL 6�� 2�� �����(14�� 1��)
// 
// 14�� anagram �ܾ��.txt�� �ٿ�޾� �ڵ��Ѵ�
// 6/15(��) - 15�� 1�� �⸻����
// 6/16(��) - ���� ����
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


// ���Ͱ� �ܾ� ���� ������ �� �ֵ��� �Ѵ�.
// first�� �����ϰ� second�� ���� �ܾ ����

struct WP : public std::pair<std::string, std::string> {
	WP(const std::string& s) : std::pair<std::string, std::string>{ s,s } {
		std::sort(first.begin(), first.end());
	}
};

//---------
int main()
//---------
{
	// save("�ҽ�.cpp");
	// [����] "�ܾ��.txt"�� �ִ� �ܾ �а� ������ ����϶�.
		
	std::ifstream in{ "�ܾ��.txt" };

	// std::string�� operator <<�� �����ε� �Ǿ��ֱ� ������ ��밡��
	std::vector<WP> v{ std::istream_iterator<std::string> {in}, {} };
	std::cout << "�ܾ��� ���� - " << v.size() << std::endl;
	
	// v�� ����� WP�� ����غ���.
	// 30000��°���� 100���� ����϶�
	/*for (auto [����, ����] : v | std::views::drop(30000)
								  | std::views::take(100)) {
		std::cout << ���� << " ---- " << ���� << std::endl;
	}*/

	/*std::sort(v.begin(), v.end(), [](const WP& a, const WP& b) {
		return a.first < b.first;
	});*/

	std::ranges::sort(v, {}, &WP::first);

	/*for (auto [����, ����] : v | std::views::drop(30000)
		| std::views::take(100)) {
		std::cout << ���� << " ---- " << ���� << std::endl;
	}*/

	// [����] ��� anagram�� ����϶�.
	auto b = v.begin();
	int cnt{};
	//std::ofstream out{"�ֳʱ׷���.txt"};
	
	std::vector<std::list<std::string>> vv;
	vv.reserve(31000);

	// [����] �ֳʱ׷� ���� ���� ���� ���� ã�ƶ�
	while (true) {
		auto i = std::adjacent_find(b, v.end(), [](const WP& a, const WP& b) {
			return a.first == b.first;
		});

		if (i == v.end())
			break;

		auto j = std::find_if_not(i + 1, v.end(), [i](const WP& a) {
			return a.first == i->first;
		});

		// [i, j]�� �ֳʱ׷� �����̴�.
		std::list<std::string> cont;
		for (auto p = i; p < j; ++p)
			cont.push_back(p->second);
		vv.push_back(cont);
		b = j;
	}

	// vv�� list�� ���� ������ �������� ����
	std::sort(vv.begin(), vv.end(), [](const std::list<std::string>& a, const std::list<std::string>& b) {
		return a.size() > b.size();
	});

	std::cout << "�ֳʱ׷� ���� �� - " << vv.begin()->size() << std::endl;

	for (const std::list<std::string>& cont : vv | std::views::take(10))
	{
		for (const std::string s : cont)
			std::cout << s << " ";
		std::cout << std::endl;
	}

}