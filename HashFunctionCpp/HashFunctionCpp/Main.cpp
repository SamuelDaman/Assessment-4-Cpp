//  Main.cpp

#include <iostream>
#include "Hash.h"

int main()
{
	tHashmap<string, int> favoriteNumbersByName = tHashmap<string, int>();

	cout << "Size: " << favoriteNumbersByName.size() << endl;
	cout << "Is Empty: " << favoriteNumbersByName.empty() << endl;
	cout << endl;


	cout << "Setting \"Terry\" to 5." << endl;
	favoriteNumbersByName["Terry"] = 5;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << endl;
	
	cout << "Setting \"Harry\" to 12." << endl;
	favoriteNumbersByName["Harry"] = 12;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << endl;

	cout << "Setting \"Larry\" to 0." << endl;
	favoriteNumbersByName["Larry"] = 0;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << endl;

	cout << "Setting \"Perry\" to 24." << endl;
	favoriteNumbersByName["Perry"] = 24;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << endl;

	cout << "Setting \"Jerry\" to 17." << endl;
	favoriteNumbersByName["Jerry"] = 17;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << endl;

	cout << "Setting \"Barry\" to 99." << endl;
	favoriteNumbersByName["Barry"] = 99;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << endl;

	cout << "Setting \"Gerry\" to 18." << endl;
	favoriteNumbersByName["Gerry"] = 18;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << endl;

	cout << "Setting \"Carry\" to 42." << endl;
	favoriteNumbersByName["Carry"] = 42;
	cout << "Printing all Keys and Values." << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl;
	cout << "Harry: " << favoriteNumbersByName["Harry"] << endl;
	cout << "Larry: " << favoriteNumbersByName["Larry"] << endl;
	cout << "Perry: " << favoriteNumbersByName["Perry"] << endl;
	cout << "Jerry: " << favoriteNumbersByName["Jerry"] << endl;
	cout << "Barry: " << favoriteNumbersByName["Barry"] << endl;
	cout << "Gerry: " << favoriteNumbersByName["Gerry"] << endl;
	cout << "Carry: " << favoriteNumbersByName["Carry"] << endl;
	cout << endl;

	cout << "Setting \"Mary\" to 65." << endl;
	favoriteNumbersByName["Mary"] = 65;
	cout << "Printing all Keys and Values." << endl;
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

	cout << "Setting \"Gary\" to 74." << endl;
	favoriteNumbersByName["Gary"] = 74;
	cout << "Printing all Keys and Values." << endl;
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

	cout << "Copying elements into new map." << endl;
	tHashmap<string, int> copyNumbersByName = favoriteNumbersByName;
	cout << endl;

	cout << "Clearing original map." << endl;
	favoriteNumbersByName.clear();
	cout << "Size: " << favoriteNumbersByName.size() << endl;
	cout << "Is Empty: " << favoriteNumbersByName.empty() << endl;
	cout << endl;

	cout << "Printing all copied Keys and Values." << endl;
	cout << "Terry: " << copyNumbersByName["Terry"] << endl;
	cout << "Harry: " << copyNumbersByName["Harry"] << endl;
	cout << "Larry: " << copyNumbersByName["Larry"] << endl;
	cout << "Perry: " << copyNumbersByName["Perry"] << endl;
	cout << "Jerry: " << copyNumbersByName["Jerry"] << endl;
	cout << "Barry: " << copyNumbersByName["Barry"] << endl;
	cout << "Gerry: " << copyNumbersByName["Gerry"] << endl;
	cout << "Carry: " << copyNumbersByName["Carry"] << endl;
	cout << "Mary: " << copyNumbersByName["Mary"] << endl;
	cout << "Gary: " << copyNumbersByName["Gary"] << endl;
	cout << endl;

	cout << "Size: " << copyNumbersByName.size() << endl;
	cout << "Is Empty: " << copyNumbersByName.empty() << endl;
	cout << endl;

	cout << "Done" << endl;

	while (true) {}
}