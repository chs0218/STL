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
#include <vector>
#include "save.h"
#include "STRING.h"

//---------
int main()
//---------
{
	//save("�ҽ�.cpp");
	// [����] "�ܾ��.txt"�� �ִ� �ܾ �а� ������ ����϶�.
		
	std::ifstream in{ "�ܾ��.txt" };

	// std::string�� operator <<�� �����ε� �Ǿ��ֱ� ������ ��밡��
	std::vector<std::string> word{ std::istream_iterator<std::string> {in}, {} };
	std::cout << word.size() << std::endl;

	// ���ĵǾ� �ֳ� Ȯ���غ���

	// ����° ���ڷ� ? �������� ���ĵǾ��ֳ� Ȯ���غ���!
	std::cout << "����? "<< std::boolalpha << std::is_sorted(word.begin(), word.end(), std::less<std::string>()) << std::endl;

	// �ߺ��� �ֳ� üũ�غ���!
	auto p = std::unique(word.begin(), word.end());
	if (p == word.end())
		std::cout << "�ߺ�X" << std::endl;
	else
		std::cout << "�ߺ�O" << std::endl;

	// [����] ���� �� �ܾ ����϶�.
	p = std::max_element(word.begin(), word.end(), [](const std::string& a, const std::string& b) {
		return a.size() < b.size();  
	});
	std::cout << "���� " <<  p->size() << ", " << *p << std::endl;


	// [����] ����� �Է��� �ܾ �ܾ�鿡 �ִ��� Ȯ���Ѵ�.
	// �ִٸ� anagram�� ã�� ȭ�鿡 ����϶�.
	while (true){
		std::string s;
		std::cout << "ã�� �ܾ��? ";
		std::cin >> s;
		
		if (!std::binary_search(word.begin(), word.end(), s)) {
			std::cout << "�ܾ �����ϴ�." << std::endl;
			continue;
		}

		// �ֳʱ׷��� ã�� ����Ѵ�.
		// word�� �� ������ �ܾ�鿡 �ִ��� Ȯ���Ѵ�.
		
		
	}
}