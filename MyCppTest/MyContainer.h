#pragma once

template <typename T>
class MyContainer
{
public:
	MyContainer()
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{}

	MyContainer(int size)
		: m_size(0)
	{
		this->m_data = new T[size];
		this->m_size = 0;
		this->m_capacity = size;
	}

	~MyContainer()
	{
		delete[] this->m_data;
		this->m_size = 0;
		this->m_capacity = 0;
	}

	void Clear()
	{
		delete[] this->m_data;
		this->m_size = 0;
		this->m_data = new T[this->m_capacity];
	}

	size_t Size() const
	{
		return this->m_size;
	}

	void Add(T item)
	{
		if (this->m_capacity == 0)
		{
			this->m_capacity = 1;
			this->m_data = new T[this->m_capacity];
			this->m_size = 1;
			this->m_data[0] = item;
		}
		else if (this->m_size < this->m_capacity)
		{
			this->m_data[m_size++] = item;
		}
		else
		{
			T* tmp = this->m_data;
			this->m_capacity *= 2;
			this->m_data = new T[this->m_capacity];
			for (int i = 0; i < this->m_size; i++)
			{
				this->m_data[i] = tmp[i];
			}
			this->m_data[this->m_size++] = item;
			delete[] tmp;
		}
	}

	T& operator[](int i) const
	{
		return this->m_data[i];
	}


private:

	T* m_data;
	size_t m_size;
	size_t m_capacity;

};

