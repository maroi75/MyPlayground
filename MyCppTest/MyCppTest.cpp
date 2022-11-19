// MyCppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "MyString.h"
#include "A.h"
#include "B.h"
#include "MyContainer.h"


void Test1(MyString&& str)
{
    str.Display();
}

void Test1(MyString& str)
{
    Test1(std::move(str));
}

void Test2(const MyString& str)
{
    str.Display();
}

std::unique_ptr<MyString> Create(const wchar_t* text)
{
    return std::make_unique<MyString>(text);
}

void Test()
{
    std::shared_ptr<MyString> foo{ new MyString {L"Foo"} };
    std::shared_ptr<MyString> bar = std::make_shared<MyString>(L"Bar");

    foo->Display();
    bar->Display();

    auto str = std::make_shared<MyString>();
    *str = *foo;
    *str << L"!";

    str->Display();


    std::vector<std::shared_ptr<MyString>> vec;
    auto str1 = Create(foo->GetText());
    *str1 << L":";
    vec.push_back(std::move(str1));




    for (const auto& it : vec)
    {
        *it << L" in Vec";
        it->Display();
        str = it;
    }




}

void Display(const std::vector<int>& vec)
{
    std::cout << "[ ";
    for (auto e : vec)
    {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

void Display(const MyContainer<std::shared_ptr<MyString>>& vec)
{
    std::cout << "[ ";
    for(int i=0;i< vec.Size();i++)
    {
        std::wcout << vec[i]->GetText() << " ";
    }
    std::cout << "]" << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";


    Test1(MyString(L"Foo"));

    MyString bar(L"Bar");


    Test1(std::move(bar));

    bar.Display();



}

