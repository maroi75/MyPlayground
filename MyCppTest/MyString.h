#pragma once

class MyString
{
public:
	MyString();
	MyString(const MyString& source);
	MyString(MyString&& source);
	explicit MyString(const wchar_t* text);
	~MyString();

	MyString& operator=(const MyString& rhs);
	MyString& operator=(MyString&& rhs) noexcept;

	MyString operator+(const MyString& rhs) const;
	MyString operator+(const wchar_t* rhs) const;

	MyString& operator+=(const MyString& rhs);
	MyString& operator+=(const wchar_t* rhs);

	MyString& operator<<(const MyString& rhs);
	MyString& operator<<(const wchar_t* rhs);

	MyString& operator--();
	MyString operator--(int rhs);
	

	const wchar_t* GetText() const;
	void Display() const;

private:
	void Append(const wchar_t* text);
	static wchar_t* Concat(const wchar_t* first, const wchar_t* second);

private:
	wchar_t* m_str;
};

