#pragma once
#include <iostream>
#include <string>

using namespace std;

class Inventory
{
private:

public:
	void Initialize(const string* container[], int capacity);
	bool isFull(const string* const container[], int capacity);
	bool isEmpty(const string* const container[], int capacity);
	bool Contains(const string* const pItem, const string* container[], int capacity);
	void Display(const string* const container[], int capacity);
	void Add(const string* const pItem, const string* container[], int capacity);
	void Remove(const string* const pItem, const string* container[], int capacity);
	int inventory();
};

