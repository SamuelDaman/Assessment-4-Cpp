// Main.cpp

#include <iostream>
#include "Sorting.h"

using std::cout;
using std::endl;

// Quick demonstration of the sorting algorithm.
int main()
{
	tSorting<int> test = tSorting<int>();	// The container being operated upon.

	test[0] = 13;
	test[1] = 54;
	test[2] = 4;
	test[3] = 18;
	test[4] = 23;
	test[5] = 78;
	test[6] = 3;
	test[7] = 5;
	test[8] = 10;
	test[9] = 42;

	cout << "Original array:" << endl;

	for (size_t i = 0; i < test.capacity(); i++)
	{
		if (i != test.capacity() - 1)
		{
			cout << test[i] << ", ";
		}
		else
		{
			cout << test[i] << endl;
		}
	}
	cout << endl;

	cout << "Sorted array:" << endl;
	test.insertionSort();

	for (size_t i = 0; i < test.capacity(); i++)
	{
		if (i != test.capacity() - 1)
		{
			cout << test[i] << ", ";
		}
		else
		{
			cout << test[i] << endl;
		}
	}

	while (true) {}
}