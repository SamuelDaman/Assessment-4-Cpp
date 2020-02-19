// Main.cpp

#include <iostream>
#include "tList.h"

using std::cout;
using std::cin;
using std::endl;

// This is a sequence of functions being performed on the list as a demonstration.
int main()
{
	tList<int> test = tList<int>();		// Original list
	tList<int> copy;					// Copy list

	cout << "Is the list empty? (0 = false) (1 = true): " << test.empty() << endl << endl;

	cout << "Pushing 5, 6, 7, then 8 to the front." << endl;
	test.push_front(5);
	test.push_front(6);
	test.push_front(7);
	test.push_front(8);
	cout << "The front node is " << test.front() << '.' << endl << endl;

	cout << "Pushing 4, 3, 2, then 1 to the back." << endl;
	test.push_back(4);
	test.push_back(3);
	test.push_back(2);
	test.push_back(1);
	cout << "The back node is " << test.back() << '.' << endl << endl;

	cout << "Is the list empty: " << test.empty() << endl << endl;

	cout << "Iterating through the list and writing out all of the variables." << endl;
	for (auto iter = test.beginFront(); iter != test.endFront(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;

	cout << "Copying current list into a new list." << endl << endl;
	copy = test;

	cout << "Iterating through the copy." << endl;
	for (auto iter = copy.beginFront(); iter != copy.endFront(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;

	cout << "Removing 1, 8, and 2 from original, then popping the front and back nodes." << endl;
	test.remove(1);
	test.remove(8);
	test.remove(2);
	test.pop_front();
	test.pop_back();
	cout << endl;

	cout << "Iterating through the original after removal." << endl;
	for (auto iter = test.beginFront(); iter != test.endFront(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;

	cout << "Iterating through the copy after removal." << endl;
	for (auto iter = copy.beginFront(); iter != copy.endFront(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;

	cout << "Iterating backwards through the copy." << endl;
	for (auto iter = copy.beginBack(); iter != copy.endBack(); --iter)
	{
		cout << *iter << endl;
	}
	cout << endl;

	cout << "Resizing the original list to a size of 9." << endl << endl;
	test.resize(9);
	cout << "New size is " << test.listSize() << '.' << endl << endl;

	cout << "Clearing original list." << endl;
	test.clear();
	cout << "Is it empty: " << test.empty() << endl << endl;

	cout << "Done.";

	while (true) {}
}