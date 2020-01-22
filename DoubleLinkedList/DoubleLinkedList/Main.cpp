//  Main.cpp

#include <iostream>
#include "tList.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tList<int> test = tList<int>();
	test.push_front(5);
	cout << "front: " << test.front() << endl;
	test.push_front(6);
	cout << "front: " << test.front() << endl;
	test.push_front(7);
	cout << "front: " << test.front() << endl;

	test.push_back(4);
	cout << "back: " << test.back() << endl;
	test.push_back(3);
	cout << "back: " << test.back() << endl;
	test.push_back(2);
	cout << "back: " << test.back() << endl;

	test.remove(7);

	cout << "front: " << test.front() << endl;

	while (true) {}
}