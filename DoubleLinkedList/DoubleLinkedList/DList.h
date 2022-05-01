#pragma once

#include <iostream>

template < typename Type = int>

class DList	
{
	
private:

	struct node
	{
		
		node * next, * prev;
		Type data;
		node(Type & _data, node * _next = nullptr, node * _prev = nullptr) : data(_data), next(_next), prev(_prev) {}
		
	};
	
	int count;
	node * first, * last;
	
		
public:
	
	DList() { first = last = nullptr; count = 0; }
	~DList();
	int GetCount() { return count; }
	void push_back(Type _data);
	Type & operator[](int _index);
	const Type & operator[](int _index) const;
	void Clear();
	void push_front(Type _data);
	void Erase(int _index);
	void printList();

};


template < typename Type>

void DList<Type>::push_back(Type _data)

{

	node* n = new node(_data, NULL, last);

	if (last)
		last->next = n;
	else
		first = n;

	last = n;
	++count;
}

template < typename Type>

DList<Type>::~DList()
{

	Clear();

}


template < typename Type>
Type& DList<Type>::operator[](int _index)
{

	node* temp = first;
	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}


template < typename Type>
const Type& DList<Type>::operator[](int _index) const
{

	node* temp = first;
	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;
	return temp->data;

}

template <typename Type>
void DList<Type>::Clear()
{
	node* temp = first;
	while (temp != NULL)
	{

		node* Copy = temp;
		Copy = temp->next;
		
		delete temp;

		temp = Copy;
		count--;
	}

	first = NULL;
	last = NULL;
}


template <typename Type>
void DList<Type>::push_front(Type _data)
{
	node* n = new node(_data, first);

	if (first)
		first->previous = n;
	else
		last = n;

	first = n;
	++count;
}


template <typename Type>
void DList<Type>::Erase(int _index)
{

	int sizeOfNodes = GetCount();
	if (_index >= sizeOfNodes)
		return;
	node* temp = first;

	if (_index == 0)
	{
		first = first->next;
	}

	if (_index == sizeOfNodes - 1)
	{
		last = last->previous;
	}
	//puts temp at index
	for (int i = 0; i < _index; i++)
	{
		temp = temp->next;

	}

	//swap the previous pointer from temp to next pointer
	if (temp->previous)
		temp->previous->next = temp->next;
	//swap the next pointer from temp to previous
	if (temp->next)
		temp->next->previous = temp->previous;
	delete temp;
	count--;
}

template <typename Type>
void DList<Type>::printList()
{
	node* n = first;
	int countsize = GetCount();

	for (int i = 0; i < countsize; i++)
	{
		std::cout << n->data << std::endl;
		n = n->next;
	}
}



