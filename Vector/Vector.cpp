﻿#include "stdafx.h"
#include "MyVector.h"


int main()
{
	try {
		MyVector test(1);
		test.print();

		test.push_back(10);
		test.push_back(20);

		test.print();

		MyVector test2(test);
		test2.push_back(30);

		test2.print();

		//int element = test.pop_back();

		//std::cout << element << std::endl;
		//test.print();

		test = test2;
		test.print();

		int i = test.get_element(2);
		std::cout << i << std::endl;

		i = test.get_element(3);
		std::cout << i << std::endl;

	//	test = *(test + test2);
	//	test.print();




	}
	catch (const std::logic_error& er) {
		std::cout << er.what() << std::endl;
	}


	
	return 0;
}
