#include "B.h"

#include <iostream>

B::B(std::string name, int age, int weight) : A::A(name, age)
{
	this->m_weight = weight;
}

void B::Display()
{
	std::cout << this->m_name << " is " << this->m_age << " years old" << " and weight " << this->m_weight << " kg" << std::endl;
}
