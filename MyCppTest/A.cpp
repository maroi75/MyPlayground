#include "A.h"

#include <iostream>

A::A(std::string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

void A::Display()
{
	std::cout << this->m_name << " is " << this->m_age << " years old" << std::endl;
}

void A::SetAge(int age)
{
	this->m_age = age;
}

int A::GetAge() const
{
	return this->m_age;
}

std::string& A::GetName()
{
	return this->m_name;
}