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
	STRING(const char* str);
	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	
	STRING operator+(const STRING& rhs) const;

	void print(const char* s);
	size_t getNum() const;			// 2022.3.30 �߰�

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};