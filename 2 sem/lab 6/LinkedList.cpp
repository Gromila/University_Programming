#include "LinkedList.h"

LinkedList::LinkedList () : _head(NULL), _tail(NULL), _count(0)	{}

LinkedList::~LinkedList()
{
	ListNode* temp;
	while (_head != NULL)
	{
		temp = _head -> _next;
		delete _head;
		_head = temp;
	}
}

void LinkedList::PushBack (Trips trip)
{
	if (_count > 0)
	{
		ListNode* temp = new ListNode;
		temp -> _next = NULL;
		temp -> _prev = _tail;
		temp -> _data = trip;
		_tail -> _next = temp;
		_tail = temp;
		_count++;
	}
	else
		if (_count == 0)
		{
			ListNode* temp = new ListNode;
			temp -> _next = NULL;
			temp -> _prev = NULL;
			temp -> _data = trip;
			_head = _tail = temp;
			_count++;
		}
}

void LinkedList::PushFront (Trips trip)
{
	if (_count > 0)
	{
		ListNode* temp = new ListNode;
		temp -> _next = _head;
		temp -> _prev = NULL;
		temp -> _data = trip;
		_head -> _prev = temp;
		_head = temp;
		_count++;
	}
	else
		if (_count == 0)
		{
			ListNode* temp = new ListNode;
			temp -> _next = NULL;
			temp -> _prev = NULL;
			temp -> _data = trip;
			_head = _tail = temp;
			_count++;
		}
}

void LinkedList::PrintList()
{
	ListNode *p = _head;
	if (!p) cout<<("Список не загружен");
	printf("        маршрут      отправление места цена\n");
	while (p)
	{
		Trips current = p -> _data;
		printf("#%3d %15s %2d.%2d.%4d %4d %5d\n", current.number, current.route, current.time.day, current.time.month, current.time.year, current.seats, current.cost);
		p = p -> _next;
	}
}

Trips LinkedList::PopFront()
{
	Trips temp = _head -> _data;
	if (_count == 1)
	{
		delete _head;
		_head = _tail = NULL;
		_count--;
	}
	else
		if (_count == 2)
		{
			delete _head;
			_tail -> _prev = NULL;
			_head = _tail;
			_count--;
		}
		else
			if (_count > 2)
			{
				ListNode* t = _head -> _next;
				delete _head;
				_head = t;
				_head -> _prev = NULL;
				_count--;
			}
	return temp;
}

Trips LinkedList::PopBack()
{
	Trips temp = _tail -> _data;
	if (_count == 1)
	{
		delete _tail;
		_head = _tail = NULL;
		_count--;
	}
	else
		if (_count == 2)
		{
			delete _tail;
			_head -> _next = NULL;
			_tail = _head;
			_count--;
		}
		else
			if (_count > 2)
			{
				ListNode* t = _tail -> _prev;
				delete _tail;
				_tail = t;
				_tail -> _next = NULL;
				_count--;
			}
	return temp;
}

ListNode* LinkedList::FindInt (int key)
{
	ListNode *p = _head;
	while (p)
	{
		if (p -> _data.number == key)
			return p;
		p = p -> _next;
	}
	return NULL;
}

void LinkedList::Remove (ListNode *key)
{
	if (_count == 1)
	{
		delete _head;
		_head = _tail = key = NULL;
		_count--;
	}
	if (_count > 1 && key != NULL)
	{
		if (key == _tail)
		{
			_tail = key -> _prev;
			delete key;
			_tail -> _next = NULL;
			key = _head;
		}
		if (key == _head)
		{
			_head = key -> _next;
			delete key;
			_head -> _prev = NULL;
			key = _head;
		}
		else
		{
			ListNode* next = key -> _next;
			ListNode* prev = key -> _prev;
			next -> _prev = prev;
			prev -> _next = next;
			delete key;
			key = next;
		}
		_count--;
	}
}