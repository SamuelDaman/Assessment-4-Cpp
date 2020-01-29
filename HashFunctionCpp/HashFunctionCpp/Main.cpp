//  Main.cpp

#include <iostream>
#include "Hash.h"

int main()
{
	tHashmap<string, int> * favoriteNumbersByName = new tHashmap<string, int>[5];

	favoriteNumbersByName[0]["Terry"] = 5;
	cout << favoriteNumbersByName[0]["Terry"] << endl;
	
	favoriteNumbersByName[1]["Harry"] = 12;
	cout << favoriteNumbersByName[1]["Harry"] << endl;

	favoriteNumbersByName[2] = tHashmap<string, int>(favoriteNumbersByName[0]);
	cout << favoriteNumbersByName[2]["Terry"] << endl;

	favoriteNumbersByName[3] = favoriteNumbersByName[1];
	cout << favoriteNumbersByName[3]["Harry"] << endl;

	favoriteNumbersByName[4]["Larry"] = 8;
	cout << favoriteNumbersByName[4]["Larry"] << endl;

	delete[] favoriteNumbersByName;

	cout << "Done" << endl;

	while (true) {}
}