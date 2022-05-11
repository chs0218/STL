//-----------------------------------------------------------------------------
// STRING.h - 자원을 관리하는 STL 관찰용 클래스
// 
// 2022.3.30							Programmed by HS
//-----------------------------------------------------------------------------


#pragma once
#include <iostream>
#include <compare>
class STRING_iterator {
public:	//	표준 반복자라면 이 다섯가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;
private:
	char* p;
public:
	STRING_iterator(char* p) : p{ p } {}

	reference operator*() const{
		return *p;
	}

	STRING_iterator& operator++() {
		++p;
		return *this;
	}

	// 2022. 4. 28 sort가 요구하는 --연산
	STRING_iterator& operator--() {
		--p;
		return *this;
	}

	// 관계연산자: <, >, <=, >=, ==, !=
	// 관계연산자를 자동으로 생성하는 우주선 연산자를 사용한다.
	// spaceship operator(three-way comparison operator)

	// withordering, stringordering
	auto operator<=>(const STRING_iterator& rhs) const = default;

	// 강순서(strong order), 약순서(week order), 부분순서(partial order)

	//bool operator!=(const STRING_iterator& rhs) const {
	//	std::cout << "이게 우선 사용" << "\n";
	//	return p != rhs.p;
	//}

	// 2022. 4. 27 sort가 요구하는 - 연산
	difference_type operator-(const STRING_iterator& rhs) const{
		return p - rhs.p;
	}

	// 2022. 4. 28 sort가 요구하는 -연산
	STRING_iterator operator-(const difference_type& d) const {
		return STRING_iterator{ p - d };
	}

	// 2022. 4. 28 sort가 요구하는 +연산
	STRING_iterator operator+(const difference_type& d) const {
		return STRING_iterator{ p + d };
	}

	
};

class STRING_reverse_iterator {
public:	//	표준 반복자라면 이 다섯가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;
private:
	char* p;
public:
	STRING_reverse_iterator(char* p) : p{ p } {}
	reference operator*() const {
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
	int id;				// 생성 시 부여
	size_t num;			// 자원 갯수
	char* p;			// 자원이 있는 곳
	static int cid;		// 객체가 생성될 때 1 증가
public:
	STRING();
	~STRING();
	STRING(const char* str);		
	STRING(const STRING& other);

	// 2022.04.07 추가(이동 생성자, 이동할당연산자)
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING& operator=(const STRING& other);
	STRING operator+(const STRING& rhs) const;
	
	// 2022. 4. 28 sort용 디폴트 정렬기준
	bool operator<(const STRING& rhs) const;

	// 2022.04.21 begin(), end() 시작
	// 2022.04.27 begin(), end() 다시 코딩
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

	size_t getNum() const;			// 2022.3.30 추가
	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	// 2022. 4. 28 추가
	friend std::istream& operator>>(std::istream&, STRING&);

	char getC() const {
		return p[0];
	}
};