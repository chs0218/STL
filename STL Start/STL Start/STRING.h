//-----------------------------------------------------------------------------
// STRING.h - 자원을 관리하는 STL 관찰용 클래스
// 
// 2022.3.30							Programmed by HS
//-----------------------------------------------------------------------------

#pragma once
#include <iostream>
class STRING {
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
	
	// 2022.04.21 begin(), end() 시작
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

	size_t getNum() const;			// 2022.3.30 추가
	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};

class STRING_iterator {
	char* p;
public:
	STRING_iterator() = default;
	STRING_iterator(char* p) : p{ p }{};
};