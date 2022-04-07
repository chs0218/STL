//-----------------------------------------------------------------------------
// STRING.cpp - �ڿ��� �����ϴ� STL ������ Ŭ����
// 
// 2022.3.30							Programmed by HS
//-----------------------------------------------------------------------------


#pragma once
#include "STRING.h"

bool ����{ false };		// �޽����� ������ true�� �ٲ��


STRING::STRING() : num{}, p{}, id{ ++cid } 
{
	if (����)
		print("����Ʈ");
}

STRING::STRING(const char* str) : num{ strlen(str) }, id{ ++cid }
{
	p = new char[num];
	memcpy(p, str, num);

	// �����޽����� �Ѹ� ����Ѵ�.
	if (����)
		print("������(*)");
}

STRING::STRING(const STRING& other) :num{ other.num }, id{ ++cid } 
{
	p = new char[num];
	memcpy(p, other.p, num);

	if (����)
		print("�������");
}

STRING::STRING(STRING&& other) noexcept : num{other.num}, id{++cid}
{
	p = other.p;
	
	other.p = nullptr;
	other.num = 0;

	if (����)
		print("�̵�����");
}

STRING& STRING::operator=(STRING&& other) noexcept
{
	if (this != &other)
	{
		if (num)
			delete[] p;
		p = other.p;
		other.num = 0;
		other.p = nullptr;
	}

	if (����)
		print("�̵��Ҵ�");
	
	return *this;
}

STRING::~STRING() {
	// �����޽����� �Ѹ� ����Ѵ�.
	if (����)
		print("�Ҹ���");
	delete[] p;
}

STRING& STRING::operator=(const STRING& other) {
	if (this == &other)
		return *this;
	if (num)
		delete[] p;

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);
	if (����)
		print("�����Ҵ�");
	return *this;
}

STRING STRING::operator+(const STRING& rhs) const {
	STRING temp;

	temp.num = num + rhs.num;
	temp.p = new char[temp.num];
	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

void STRING::print(const char* s) {
	std::cout << s << ", [" << id << "] ��ü:" << this;
	if (num) {
		std::cout << " �ڿ���: " << num << " �ּ�: " << (void*)p;
	}
	else
		std::cout << " �ڿ� ����";
	std::cout << std::endl;
}

size_t STRING::getNum() const{
	return num;
}

int STRING::cid{};

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];

	return os;
}