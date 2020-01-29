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
	return (int)val[0] * 2654435761 % std::numeric_limits<size_t>::max();
}

template<typename K, typename V>
class tHashmap
{
	V * data;
	size_t dataCapacity;

public:
	tHashmap()
	{
		dataCapacity = 30;
		data = new V[dataCapacity];
	}
	tHashmap(const tHashmap& other)
	{
		dataCapacity = other.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = other.data[i];
		}
	}
	tHashmap& operator=(const tHashmap& rhs)
	{
		dataCapacity = rhs.dataCapacity;
		data = new V[dataCapacity];
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = rhs.data[i];
		}
		return *this;
	}
	~tHashmap()
	{
		delete data;
	}

	V& operator[] (const K& key)
	{
		size_t index;
		cout << typeid(key).name() << endl;
		if (typeid(key).name() == "char")
		{
			index = (size_t)key[0] * 2654435761 % dataCapacity;
		}
		else
		{
			index = 0;
		}
		return data[index];
	}
};