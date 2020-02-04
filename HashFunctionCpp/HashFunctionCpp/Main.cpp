//  Main.cpp

#include <iostream>
#include "Hash.h"

int main()
{
	tHashmap<string, int> favoriteNumbersByName = tHashmap<string, int>();

	//cout << "Value: " << favoriteNumbersByName.at("Terry") << endl;

	cout << "Size: " << favoriteNumbersByName.size() << endl;
	cout << "Is Empty: " << favoriteNumbersByName.empty() << endl;
	cout << endl;

	favoriteNumbersByName["Terry"] = 5;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << endl;
	
	favoriteNumbersByName["Harry"] = 12;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << endl;

	favoriteNumbersByName["Larry"] = 0;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << endl;

	favoriteNumbersByName["Perry"] = 24;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << endl;

	favoriteNumbersByName["Jerry"] = 17;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << endl;

	favoriteNumbersByName["Barry"] = 99;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << endl;

	favoriteNumbersByName["Gerry"] = 18;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << endl;

	favoriteNumbersByName["Carry"] = 42;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << "Carry: " << favoriteNumbersByName["Carry"] << endl;
	cout << endl;

	favoriteNumbersByName["Mary"] = 65;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << "Carry: " << favoriteNumbersByName["Carry"] << endl;
	cout << "Mary: " << favoriteNumbersByName["Mary"] << endl;
	cout << endl;

	favoriteNumbersByName["Gary"] = 74;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << "Carry: " << favoriteNumbersByName["Carry"] << endl;
	cout << "Mary: " << favoriteNumbersByName["Mary"] << endl;
	cout << "Gary: " << favoriteNumbersByName["Gary"] << endl;
	cout << endl;

	cout << "Size: " << favoriteNumbersByName.size() << endl;
	cout << "Is Empty: " << favoriteNumbersByName.empty() << endl;
	cout << endl;

	cout << "Done" << endl;

	while (true) {}
}