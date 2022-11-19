#pragma once

#include "A.h"

class B : public A
{
public:
	B(std::string name, int age, int weight);

	void Display();

private:
	int m_weight;
};

