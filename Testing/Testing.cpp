#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
	map <string, int> test;
	test["a"] = 1;
	test["b"] = 2;
	test["c"] = 3;
	test["a"] = 4;
	
	for (auto m : test)
		cout << m.first << " - " << m.second << endl;



    return 0;
}

