//-----------------------------------------------------------------------------
// STRING.h - �ڿ��� �����ϴ� STL ������ Ŭ����
// 
// 2022.3.30							Programmed by HS
//-----------------------------------------------------------------------------


#pragma once
#include <iostream>
#include <compare>
class STRING_iterator {
	char* p;
public:
	STRING_iterator(char* p) : p{ p } {}

	char& operator*() const{
		return *p;
	}

	STRING_iterator& operator++() {
		++p;
		return *this;
	}

	// ���迬����: <, >, <=, >=, ==, !=
	// ���迬���ڸ� �ڵ����� �����ϴ� ���ּ� �����ڸ� ����Ѵ�.
	// spaceship operator(three-way comparison operator)

	// withordering, stringordering
	auto operator<=>(const STRING_iterator& rhs) const = default;

	// ������(strong order), �����(week order), �κм���(partial order)

	bool operator!=(const STRING_iterator& rhs) const {
		std::cout << "�̰� �켱 ���" << "\n";
		return p != rhs.p;
	}

	// 2022. 4. 27 sort�� �䱸�ϴ� - ����
	char* STRING_iterator operator-(const STRING_iterator& rhs) const{
		return p - rhs.p;
	}

};

class STRING_reverse_iterator {
	char* p;
public:
	STRING_reverse_iterator(char* p) : p{ p } {}
	char& operator*() const {
		return *(p - 1);
	}

	STRING_reverse_iterator& operator++() {
		--p;
		return *this;
	}
	auto operator<=>(const STRING_reverse_iterator& rhs) const = default;
	bool operator!=(const STRING_reverse_iterator& rhs) const {
		return p != rhs.p;
	}

};


class STRING {
public:
	// 2022. 4. 27
	using iterator = STRING_iterator;
	using reverse_iterator = STRING_reverse_iterator;

private:
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
	// 2022.04.27 begin(), end() �ٽ� �ڵ�
	iterator begin() const {
		return iterator{ p };
	}

	iterator end() const {
		return iterator{ p + num };
	}

	reverse_iterator rbegin() const {
		return reverse_iterator{ p + num };
	}

	reverse_iterator rend() const {
		return reverse_iterator{ p };
	}


	size_t getNum() const;			// 2022.3.30 �߰�
	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};
