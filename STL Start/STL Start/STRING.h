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
	STRING(const char* str);
	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	
	STRING operator+(const STRING& rhs) const;

	void print(const char* s);
	size_t getNum() const;			// 2022.3.30 추가

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};