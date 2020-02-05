//  Hash.h

#pragma once

#include <iostream>
#include <limits>
#include <string.h>

using std::cout;
using std::endl;
using std::string;

// Template Declaration for hash.
template<typename T>
size_t hash(const T& val)
{
	T::please_specialize_this_template_for_your_type;
}

// Template Specialization for int
template<>
size_t hash<int>(const int& val)
{
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template Specialization for char
template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template Specialization for c-strings
template<>
size_t hash<char*>(char * const& val)
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

// Template Specialization for strings
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
	V * data;				// Buffer holding all potential pairs in the hashmap
	K * dataKey;			// Buffer holding information on the keys in the hashmap
	size_t dataCapacity;	// Size of the above buffers.

public:
	// Constructs the hashmap with a size of 10.
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
	// Copies one map into another by constructor.
	tHashmap(const tHashmap& other)
	{
		dataCapacity = other.dataCapacity;
		data = new V[dataCapacity];
		data = other.data;
		dataKey = other.dataKey;
	}
	// Copies one map into another by assignment.
	tHashmap& operator=(const tHashmap& rhs)
	{
		dataCapacity = rhs.dataCapacity;
		data = new V[dataCapacity];
		data = rhs.data;
		dataKey = rhs.dataKey;
		return *this;
	}
	// Cleans up any underlying data.
	~tHashmap()
	{
		delete data;
		delete dataKey;
	}

	// Returns the object at a given key.
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

	// Returns value associated with given key.
	// Errors if the key has not yet been assigned to.
	V& at(const K& key)
	{
		auto index = hash(key) % dataCapacity;
		if (dataKey[index] != K())
		{
			return data[index];
		}
	}

	// Removes all elements from the contatiner.
	void clear()
	{
		dataKey = nullptr;
		data = nullptr;
	}
	// Returns the number of elements in the container.
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
	// Returns true if there are no elements, otherwise returns false.
	bool empty() const
	{
		if (size() == 0)
		{
			return true;
		}
		return false;
	}
};