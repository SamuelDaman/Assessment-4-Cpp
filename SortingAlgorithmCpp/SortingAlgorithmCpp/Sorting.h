// Sorting.h

#pragma once

using std::swap;

template<typename T>
class tSorting
{
	T * arr;				// The array that stores the values to be sorted.
	size_t arrCapacity;		// The capacity of the array.

public:
	// Sets the array and its capacity to their default values.
	tSorting()
	{
		arrCapacity = 10;
		arr = new T[arrCapacity];
	}

	// Changes the array's size to the given value.
	void resize(size_t newCapacity)
	{
		T * newArr = arr;
		arr = new T[newCapacity];
		for (size_t i = 0; (i < arrCapacity) && (i < newCapacity); i++)
		{
			arr[i] = newArr[i];
		}
		arrCapacity = newCapacity;
	}

	// Returns the value at the given index.
	T& operator[] (size_t index)
	{
		if (index < arrCapacity)
		{
			return arr[index];
		}
	}

	// Returns the capacity of the array.
	size_t capacity() const
	{
		return arrCapacity;
	}

	// Sorts the array using the insertion sorting method.
	void insertionSort()
	{
		bool isSorted = false;
		for (size_t i = 0; i < arrCapacity; i++)
		{
			isSorted = true;
			for (size_t j = i; (j >= 0) && (j <= i); j--)
			{
				if (arr[i] < arr[j])
				{
					swap(arr[i], arr[j]);
					i = j;
					isSorted = false;
				}
			}
			if (i == arrCapacity - 1 && isSorted == false)
			{
				i = 0;
			}
		}
	}
};