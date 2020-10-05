#pragma once
#include <iostream>
using namespace std;

class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		Link(int val, Link *nxt) : value(val), next(nxt) {}
		Link(const Link &source) : value(source.value), next(source.next) {}
		int value;
		Link * next;
	};
public:
	List &  operator =(List);

	List() : head(NULL) {}
	List(const List&);
	~List(); 

	void add(int value);
	int firstElement() const;
	bool search(const int &value) const;
	bool isEmpty() const { return head == NULL; }
	void removeFirst();
	List insert(int); 
	List remove(int);

	friend List merge(List lst1, List lst2);
	friend void makeSet(List &lst);

	friend istream& operator >> (istream& in, List& l);
	friend ostream& operator << (ostream& os, List& l);

protected:

	Link* head;
};