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
	test.push_back(1);
	cout << "back: " << test.back() << endl;

	test.remove(7);
	//test.remove(6);
	//test.remove(5);
	//test.remove(4);
	//test.remove(3);
	//test.remove(2);
	test.remove(1);

	cout << "front: " << test.front() << endl;
	cout << "back: " << test.back() << endl;

	while (true) {}
}