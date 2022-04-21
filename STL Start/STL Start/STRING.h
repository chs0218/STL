//-----------------------------------------------------------------------------
// STRING.h - �ڿ��� �����ϴ� STL ������ Ŭ����
// 
// 2022.3.30							Programmed by HS
//-----------------------------------------------------------------------------

#pragma once
#include <iostream>
class STRING {
	int id;				// ���� �� �ο�
	size_t num;			// �ڿ� ����
	char* p;			// �ڿ��� �ִ� ��
	static int cid;		// ��ü�� ������ �� 1 ����
public:
	STRING();
	~STRING();
	STRING(const char* str);		
	STRING(const STRING& other);

	// 2022.04.07 �߰�(�̵� ������, �̵��Ҵ翬����)
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING& operator=(const STRING& other);
	STRING operator+(const STRING& rhs) const;
	
	// 2022.04.21 begin(), end() ����
	STRING_iterator begin() {
		return STRING_iterator(p);
	};

	STRING_iterator end() {
		return STRING_iterator(p + num);
	}

	STRING_iterator rbegin() {
		return STRING_iterator(p + num);
	};

	STRING_iterator rend() {
		return STRING_iterator(p);
	}

	size_t getNum() const;			// 2022.3.30 �߰�
	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};

class STRING_iterator {
	char* p;
public:
	STRING_iterator() = default;
	STRING_iterator(char* p) : p{ p }{};
};