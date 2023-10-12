#pragma once
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Credit: Erik Santana

char inputChar(string prompt, string options);
void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

//Pre-Condition: The MyBag class has two private member variables(pointers): int size & int* capacity. And a Vector called myBag that works with integers.
//Post-Condition: This class mimicks a bag that grows and shrinks with integers. MyBag can also be sorted and searched through using an index.
class MyBag
{
private:
	vector<int> myBag;
	int* newValue = new int[myBag.size()];
	int size;
	int capacity;

public:
	MyBag(); // No Argument Constructor
	MyBag(int newSize, int newCapacity); // Argument Constructor
	~MyBag(); // Destructor

	void setSize(int newSize); // Setter(Mutator)
	int getSize() const; // Getter(Accessor)

	void setCapacity(int newCapacity); // Setter(Mutator)
	int getCapacity() const; // Getter(Accessor)

	void subMenu(); // Logic and main MyBag function with menu.
};