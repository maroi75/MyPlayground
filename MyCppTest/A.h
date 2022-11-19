#pragma once

#include <string>

class A
{
public:
	A(std::string name, int age);
	//A(const A&) = delete;
	//A(A&&) = delete;
	virtual void Display();

	void SetAge(int age);
	int GetAge() const;

	std::string& GetName();

protected:
	std::string m_name;
	int m_age;
};

