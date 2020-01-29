//  Hash.h

#pragma once

#include <iostream>
#include <limits>
#include <string.h>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;

template<typename T>
size_t hash(const T& val)
{
	T::please_specialize_this_template_for_your_type;
}

template<>
size_t hash<int>(const int& val)
{
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<>
size_t hash<string>(const string& val)
{
	int hashSum = 0;
	size_t size = 0;
	while (val[size] != NULL)
	{
		size++;
	}
	for (size_t i = 0; i < size; i++)
	{
		hashSum += (int)val[i] * 2654435761 % std::numeric_limits<size_t>::max();
	}
	return hashSum;
}

template<typename K, typename V>
class tHashmap
{
	V * data;
	bool * isTaken;
	size_t dataCapacity;

public:
	tHashmap()
	{
		dataCapacity = 10;
		data = new V[dataCapacity];
		isTaken = new bool[dataCapacity]{ false };
	}
	tHashmap(const tHashmap& other)
	{
		dataCapacity = other.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = other.data[i];
			isTaken[i] = other.isTaken[i];
		}
	}
	tHashmap& operator=(const tHashmap& rhs)
	{
		dataCapacity = rhs.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = rhs.data[i];
			isTaken[i] = rhs.isTaken[i];
		}
		return *this;
	}
	~tHashmap()
	{
		delete data;
	}

	V& operator[] (const K& key)
	{
		auto index = hash(key) % dataCapacity;
		return data[index];
		/*if (data[index] == V())
		{
			return data[index];
		}
		else
		{
			size_t i = index;
			while (true)
			{
				if (data[i] == V())
				{
					return data[i];
				}
				i++;
				if (i == dataCapacity - 1)
				{
					i = 0;
				}
				if (i == index - 1)
				{
					break;
				}
			}
			return data[index];
		}*/
	}
};