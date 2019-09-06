#pragma once
#include <iostream>
#include <string>

using namespace std;

class Inventory
{
private:

public:
	//initializes inventory
	void Initialize(const string* container[], int capacity);

	//checks to see if inventory is full
	bool isFull(const string* const container[], int capacity);

	//checks to is if inventory is empty
	bool isEmpty(const string* const container[], int capacity);

	//tests if an item is in inventory
	bool Contains(const string* const pItem, const string* const container[], int capacity);

	//displays the items in the inventory
	void Display(const string* const container[], int capacity);

	//adds an item to the inventory
	void Add(const string* const pItem, const string* container[], int capacity);

	//removes an item from the inventory
	void Remove(const string* const pItem, const string* container[], int capacity);

	

	int itemNumber;			//number of the item to add or remove
};

