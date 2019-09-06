#include "Inventory.h"
#include <iostream>
#include <string>

using namespace std;

void Inventory::Initialize(const string* container[], int capacity)
{
	//set all elements to NULL
	for (int i = 0; i < capacity; ++i)
	{
		container[i] = NULL;
	}
}

bool Inventory::isFull(const string* const container[], int capacity)
{
	bool full = true;
	int i = 0;

	while (full && i < capacity)
	{
		//if there's at least one empty slot...
		if (container[i] == NULL)
		{
			//then the container isn't full
			full = false;
		}
		++i;
	}
	return full;
}

bool Inventory::isEmpty(const string* const container[], int capacity)
{
	bool empty = true;
	int i = 0;

	while (empty && i < capacity)
	{
		//if a slot isn't empty
		if (container[i] != NULL)
		{
			//then the container isn't empty
			empty = false;
		}
		++i;
	}
	return empty;
}

bool Inventory::Contains(const string* const pItem, const string* const container[], int capacity)
{
	bool has = false;
	int i = 0;

	while (!has && i < capacity)
	{
		if (container[i] == pItem)
		{
			has = true;
		}
		++i;
	}
	return has;
}

void Inventory::Display(const string* const container[], int capacity)
{
	//if container is empty, display message saying so and return
	if (isEmpty(container, capacity))
	{
		cout << "<Empty>" << endl;
		return;
	}
	//Otherwise, send all strings pointed to by elements of container to cout
	for (int i = 0; i < capacity; ++i)
	{
		if (container[i] != NULL)
		{
			cout << *(container[i]) << endl;
		}
	}
}

void Inventory::Add(const string* const pItem, const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		return;
	}

	if (Contains(pItem, container, capacity))
	{
		cout << "I can't hold anymore of that.";
		cout << endl;
		return;
	}

	if (isFull(container, capacity))
	{
		cout << "My inventory is full." << endl;
		return;
	}

	//find first null pointer in container, point it to string pItem points to
	bool found = false;
	int i = 0;
	while (!found && i < capacity)
	{
		if (container[i] == NULL)
		{
			container[i] = pItem;			//add pointer to an item
			found = true;
		}
		++i;
	}
}

void Inventory::Remove(const string* const pItem, const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		return;
	}

	//set element that is equal to pItem to NULL
	bool found = false;
	int i = 0;

	while (!found && i < capacity)
	{
		if (container[i] == pItem)
		{
			container[i] = NULL;			//remove pointer to an item
			found = true;
		}
		++i;
	}

	//if item wasn't found, say so
	if (!found)
	{
		cout << "Item not found." << endl;
	}
}


