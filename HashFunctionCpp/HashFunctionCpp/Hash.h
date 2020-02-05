//  Hash.h

#pragma once

#include <iostream>
#include <limits>
#include <string.h>

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
		if (dataKey[index] == K())
		{
			dataKey[index] = key;
			return data[index];
		}
		else if (dataKey[index] == key)
		{
			return data[index];
		}
		else if (dataKey[index] != K())
		{
			size_t i = index;
			bool l = false;
			while (true)
			{
				if (dataKey[i] == K() || dataKey[i] == key)
				{
					dataKey[i] = key;
					return data[i];
				}
				else
				{
					i++;
				}
				if (i == dataCapacity - 1)
				{
					i = 0;
					l = true;
				}
				if (i == index - 1 && l == true)
				{
					break;
				}
			}
		}
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

	void clear()
	{
		dataKey = nullptr;
		data = nullptr;
	}
	size_t size() const
	{
		if (data != nullptr && dataKey != nullptr)
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
		else
		{
			return 0;
		}
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