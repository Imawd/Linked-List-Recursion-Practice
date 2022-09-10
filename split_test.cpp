#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;


int main () 
{

	Node* Node12 = new Node(12, NULL);
	Node* Node11 = new Node(11, Node12);
	Node* Node10 = new Node(10, Node11);
	Node* Node9 = new Node(9, Node10);
	Node* Node8 = new Node(8, Node9);
	Node* Node7 = new Node(7, Node8);
	Node* Node6 = new Node(6, Node7);
	Node* Node5 = new Node(5, Node6);
	Node* Node4 = new Node(4, Node5);
	Node* Node3 = new Node(3, Node4);
	Node* Node2 = new Node(2, Node3);
	Node* Node1 = new Node(1, Node2);
	
	
	

	Node* odds;
	Node* evens;

	split (Node1, odds, evens);

	cout << "Odds: ";
	while (odds != nullptr)
	{
		cout << odds->value << ", ";
		odds = odds->next;
	}

	cout << "Evens: ";
	while (evens != nullptr)
	{
		cout << evens->value << ", ";
		evens = evens->next;
	}


	delete[] Node1;
	delete[] Node2;
	delete[] Node3;
	delete[] Node4;
	delete[] Node5;
	delete[] Node6;
	delete[] Node7;
	delete[] Node8;
	delete[] Node9;
	delete[] Node10;
	delete[] Node11;
	delete[] Node12;


}