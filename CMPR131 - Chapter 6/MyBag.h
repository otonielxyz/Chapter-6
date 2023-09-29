#pragma once
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

char inputChar(string prompt, string options);
void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

class MyBag
{
private:
	vector<int> myBag;
	int size;
	int capacity;

public:

	MyBag();
	MyBag(int newSize, int newCapacity);
	~MyBag();
	void subMenu();

	void setSize(int newSize);
	int getSize();

	void setCapacity(int newCapacity);
	int getCapacity();

};