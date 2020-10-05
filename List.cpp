#include "List.h"

List &List::operator=(List l)
{
	Link* p = l.head;
	if (p == NULL)
		head = NULL;
	else
	{
		while (p != NULL)
		{
			insert(p->value);
			p = p->next;
		}
	}

	return *this;
}

List::List(const List &l)
{
	if (l.head == NULL)
	{
		head = NULL;
		return;
	}
	Link *src, *trg;
	head = new Link(l.head->value, NULL);
	src = l.head;
	trg = head;
	while (src->next != NULL)
	{
		trg->next = new Link(src->next->value, NULL);
		src = src->next;
		trg = trg->next;
	}
}

List::~List()
{
	for (Link *p = head; p != NULL; p = p->next)
		p->next = NULL;
	head = NULL;
}

void List::add(int value)
{
	head = new Link(value, head);
	if (head == NULL)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	if(isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool List::search(const int & val) const
{
	for (Link *p = head; p != NULL; p = p->next)
	{
		if (p->value == val)
			return true;
	}
	return false;
}

void List::removeFirst()
{
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link *p = head;
	head = head->next;
	p->next = NULL;
	delete p;
}

List List::insert(int key)
{
	
	if (head==NULL || head->value >= key)
	{
		add(key);
		return *this;
	}
	else
	{
		Link* next;
		for (Link* p = head; p != NULL; p = next)
		{
			next = p->next;
			if (next == NULL)
			{
				Link* newNode = new Link(key, NULL);
				p->next = newNode;
				return *this;
			}
			if (next->value > key)
			{
				Link* newNode = new Link(key, next);
				p->next = newNode;
				return *this;
			}
		}
	}

}

List List::remove(int x)
{
	if (head->value == x)
	{
		Link *node = head;
		head = head->next;
		node->next = NULL;
		delete node;
		return *this;
	}
	Link *nex;
	for (Link *p=head; p != NULL; p = p->next)
	{
		nex = p->next;
		if (nex->value == x)
		{
			p->next = nex->next;
			nex->next = NULL;
			delete nex;
			return *this;
		}
	}
	throw "value not found";
}

List merge(List lst1, List lst2)
{
	List l3;
	List::Link *p1 = lst1.head;
	List::Link *p2 = lst2.head;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->value >= p2->value)
		{
			l3.insert(p2->value);
			p2 = p2->next;
		}
		else
		{
			l3.insert(p1->value);
			p1 = p1->next;
		}
	}
	while (p2 != NULL)
	{
		l3.insert(p2->value);
		p2 = p2->next;
	}
	while (p1 != NULL)
	{
		l3.insert(p1->value);
		p1 = p1->next;
	}
	return l3;
}

void makeSet(List & lst)
 {
	 for (List::Link* p = lst.head; p != NULL; p = p->next)
		 if (p->next != NULL && p->value == (p->next)->value)
		 {
			 List::Link* nodeRemove = p->next;
			 p->next = p->next->next;
			 nodeRemove->next = NULL;
			 delete nodeRemove;
		 }
 }

 istream & operator>>(istream & in, List & l)
{
	int val1, val2;
	in >> val1 >> val2;
	l.add(val1);
	while (val1 < val2)
	{
		l.add(val2);
		val1 = val2;
		in >> val2;
	}
	return in;
}

ostream & operator<<(ostream & os, List & l)
{
	for (List::Link *p = l.head; p != NULL; p = p->next)
		os << p->value << " " << endl; 
	return os;
}
