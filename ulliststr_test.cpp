/* Write your test code for the ULListStr in this file */
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test1; //test push_back


  test1.push_back("U"); //test empty

	std::cout << test1.get(0) << endl;
	std::cout << "Testing push_back() with one item" << endl;
	if(test1.get(0) == "U") cout << "Test passed!" << endl << endl;

  test1.push_back("S"); //test multiple items
  test1.push_back("C");
  test1.push_back("-");
  test1.push_back("T");
  test1.push_back("R");
  test1.push_back("O");
  test1.push_back("J");
  test1.push_back("A");
	test1.push_back("N");
  


	for (size_t i = 0; i < 10; i++)
	{
		std::cout << test1.get(i);
	}

	for (int i = 0; i < 5; i++) //test pop_front with multiple items
	{
		test1.pop_front();
	}

	std::cout << endl << "Testing pop_front() with multiple items: popping 5 chars from front expecting: 'R O J A N' " << endl;
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << test1.get(i) << " ";
	}

	cout << endl << endl;


	std::cout << "Testing pop_front() with one item" << endl;

	for (int i = 0; i < 4; i++) //test pop_front with one item
	{
		test1.pop_front();
	}

	std::cout << test1.get(0) << endl;

	test1.pop_front();

	if (test1.size() == 0) std::cout << "Test passed!" << endl << endl;

	test1.clear();



	std::cout << "Testing pop_back() with one item" << endl;

	test1.push_back("U");
	test1.pop_back();

	if (test1.size() == 0) std::cout << "Test passed!" << endl << endl;

	test1.clear();

	std::cout << "Testing pop_back() with multiple items" << endl;

	test1.push_back("U");
	test1.push_front("S"); 
  test1.push_back("C");

	for (int i = 0; i < 3; i++)
	{
		test1.pop_back();
	}


	if (test1.size() == 0) std::cout << "Test passed!" << endl << endl;

	test1.clear();

	ULListStr test2;	//test push_front

	std::cout << "Testing push_front with empty list" << endl;

	test2.push_front("A"); //when list is empty
	std::cout << test2.get(0) << endl;
	if (test2.get(0) == "A") std::cout << "Test passed!" << endl << endl;

	test2.push_front("R"); //multiple items push_front
	test2.push_front("E");
	test2.push_front("-");
	test2.push_front("W");
	test2.push_front("E");
	test2.push_front("-");
	test2.push_front("T");
	test2.push_front("H");
	test2.push_front("E");
	test2.push_front("R");
	test2.push_front("E");
	test2.push_front("-");
	test2.push_front("Y");
	test2.push_front("E");
	test2.push_front("T");

	std::cout << test2.get(15) << test2.get(14) << test2.get(13) << endl;

	if(test2.get(15) == "A" && test2.get(14) == "R" && test2.get(13) == "E") cout << "Test passed!" << endl << endl;

	test2.clear();

	ULListStr test3;	//test push_front and push_back combo

	std::cout << "Testing push_back() and push_front() combo" << endl;

	test3.push_back("U");
	test3.push_front("S"); 
  test3.push_back("C");
	test3.push_front("Y");
	test3.push_front("E");
	test3.push_front("T");
	test3.push_back("J");
  test3.push_back("A");
	test3.push_back("N");
	
	std::cout << test3.get(0) << test3.get(1) << test3.get(2) << test3.get(3) << endl;

	if (test3.get(0) == "T" && test3.get(1) == "E" && test3.get(2) == "Y" && test3.get(3) == "S") 
	{
		std::cout << "Test passed!" << endl;
	}

	std::cout << test3.get(5) << test3.get(6) << test3.get(7) << test3.get(8) << endl;


	if (test3.get(5) == "C" && test3.get(6) == "J" && test3.get(7) == "A" && test3.get(8) == "N") 
	{
		std::cout << "Test passed!" << endl << endl;
	}

	std::cout << "Testing back()" << endl;

	std::cout << test3.back() << " should be the same as " << test3.get(8) << endl;

	if (test3.back() == test3.get(8)) std::cout << "Test passed!" << endl << endl;

	std::cout << "Testing back() in succession" << endl;

	int count = 0;

	for (int i = 0; i < 3; i++)
	{
		if (test3.size() != 0)
		{
			test3.pop_back();
			std::cout << test3.back() << " should be the same as " << test3.get(test3.size() - 1) << endl;
			if (test3.back() == test3.get(test3.size() - 1)) count++;
		}
	}
	if (count == 3) std::cout << "Test passed!" << endl << endl;

	std::cout << "Testing front()" << endl;
	std::cout << test3.front() << " should be the same as " << test3.get(0) << endl;
	if (test3.front() == test3.get(0)) std::cout << "Test passed!" << endl << endl;

	std::cout << "Testing front() in succession" << endl;

	count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (test3.size() != 0)
		{
			test3.pop_front();
			std::cout << test3.front() << " should be the same as " << test3.get(0) << endl;
			if (test3.front() == test3.get(0)) count++;
		}
	}

	if (count == 3) std::cout << "Test passed!" << endl << endl;

	

  return 0;
}
