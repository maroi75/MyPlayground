#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString()
{
	std::wcout << "Empty constructor" << std::endl;
	this->m_str = new wchar_t[1];
	this->m_str[0] = L'\0';
}

MyString::MyString(const MyString& source)
{
	std::wcout << "Copy constructor " << source.m_str << std::endl;
	auto size = wcslen(source.m_str) + 1;
	this->m_str = new wchar_t[size];
	wcscpy_s(this->m_str, size, source.m_str);
}

MyString::MyString(MyString&& source)
{
	std::wcout << "Copy move constructor " << source.m_str << std::endl;
	this->m_str = source.m_str;
	source.m_str = nullptr;
}


MyString::MyString(const wchar_t* text)
{
	std::wcout << "Constructor " << text << std::endl;
	if (text == nullptr)
	{
		this->m_str = new wchar_t[1];
		this->m_str[0] = L'\0';
		return;
	}

	auto size = wcslen(text) + 1;
	this->m_str = new wchar_t[size];
	wcscpy_s(this->m_str, size, text);
}

MyString::~MyString()
{
	if (this->m_str != nullptr)
	{
		std::wcout << "Destructor on " << this->m_str << std::endl;
		delete[] this->m_str;
		this->m_str = nullptr;
	}
	else
	{
		std::wcout << "Destructor on empty" << std::endl;
	}
}

MyString& MyString::operator=(const MyString& rhs)
{
	std::wcout << "Assignment operator on" << m_str << " whith " << rhs.m_str << std::endl;

	if (this == &rhs)
	{
		return *this;
	}

	delete[] this->m_str;
	auto size = wcslen(rhs.m_str) + 1;
	this->m_str = new wchar_t[size];
	wcscpy_s(this->m_str, size, rhs.m_str);

	return *this;
}

MyString& MyString::operator=(MyString&& rhs) noexcept
{
	std::wcout << "Assignment move operator " << rhs.m_str << std::endl;

	if (this == &rhs)
	{
		return *this;
	}

	delete[] this->m_str;
	this->m_str = rhs.m_str;
	rhs.m_str = nullptr;

	return *this;
}

MyString MyString::operator+(const MyString& rhs) const
{
	std::wcout << "Add operator with MyString" << std::endl;
	auto newStr = Concat(this->m_str, rhs.m_str);
	MyString str(newStr);
	delete[] newStr;
	return str;
}

MyString MyString::operator+(const wchar_t* rhs) const
{
	std::wcout << "Add operator with wchar_t" << std::endl;

	auto newStr = Concat(this->m_str, rhs);
	MyString str(newStr);
	delete[] newStr;
	return str;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	std::wcout << "Unary add operator with MyString" << std::endl;

	return this->operator<<(rhs);
}

MyString& MyString::operator+=(const wchar_t* rhs)
{
	std::wcout << "Unary add operator with wchar_t" << std::endl;

	return this->operator<<(rhs);
}

MyString& MyString::operator<<(const MyString& rhs)
{
	std::wcout << "Left shift operator with MyString" << std::endl;

	this->Append(rhs.m_str);

	return *this;
}

MyString& MyString::operator<<(const wchar_t* rhs)
{
	std::wcout << "Left shift operator with wchar_t" << std::endl;

	this->Append(rhs);

	return *this;
}

MyString& MyString::operator--()
{
	std::wcout << "Decrement unary operator with MyString" << std::endl;

	auto size = wcslen(this->m_str);
	if (size == 0)
	{
		return *this;
	}

	this->m_str[size - 1] = '\0';

	return *this;
}

MyString MyString::operator--(int rhs)
{
	std::wcout << "Decrement binary operator with MyString" << std::endl;

	MyString tmp(*this);
	this->operator--();

	return tmp;
}

void MyString::Append(const wchar_t* text)
{
	auto oldStr = this->m_str;
	this->m_str = Concat(this->m_str, text);

	delete[] oldStr;
}

wchar_t* MyString::Concat(const wchar_t* first, const wchar_t* second)
{
	auto oldSize = wcslen(first);
	auto size = oldSize + wcslen(second) + 1;
	auto newStr = new wchar_t[size];

	wcscpy_s(newStr, size, first);
	wcscat_s(newStr, size, second);

	return newStr;
}

const wchar_t* MyString::GetText() const
{
	return this->m_str;
}

void MyString::Display() const
{
	auto size = wcslen(this->m_str);
	if (size > 1)
	{
		std::wcout << this->m_str << " : size " << size << std::endl;
	}
	else
	{
		std::wcout << "Empty" << std::endl;
	}
}