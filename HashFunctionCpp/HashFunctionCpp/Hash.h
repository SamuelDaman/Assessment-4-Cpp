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
	K * dataKey;
	size_t dataCapacity;

public:
	tHashmap()
	{
		dataCapacity = 10;
		data = new V[dataCapacity];
		dataKey = new K[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = NULL;
		}
	}
	tHashmap(const tHashmap& other)
	{
		dataCapacity = other.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = other.data[i];
			dataKey[i] = other.dataKey[i];
		}
	}
	tHashmap& operator=(const tHashmap& rhs)
	{
		dataCapacity = rhs.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = rhs.data[i];
			dataKey[i] = rhs.dataKey[i];
		}
		return *this;
	}
	~tHashmap()
	{
		delete data;
		delete dataKey;
	}

	V& operator[](const K& key)
	{
		auto index = hash(key) % dataCapacity;
		dataKey[index] = key;
		return data[index];
	}

	V& at(const K& key)
	{
		auto index = hash(key) % dataCapacity;
		if (dataKey[index] != K())
		{
			return data[index];
		}
	}

	size_t count(const K& key)
	{

	}

	void clear()
	{
		dataKey = nullptr;
		data = nullptr;
	}
	size_t size() const
	{
		size_t sizeCount = 0;
		for (size_t i = 0; i < dataCapacity; i++)
		{
			if (data[i] != NULL || dataKey[i] != K())
			{
				sizeCount++;
			}
		}
		return sizeCount;
	}
	bool empty() const
	{
		if (size() == 0)
		{
			return true;
		}
		return false;
	}
};