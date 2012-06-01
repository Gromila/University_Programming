#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define MAXTOURS (INT_MAX / sizeof(Trips))

typedef struct date
{
	int day;
	int month;
	int year;
} Date; 

typedef struct trips 
{  
	int number;
	char route[15];
	Date time;
	int seats;
	int cost;
} Trips;   

class ListNode
{
public:
	Trips _data;
	ListNode* _next;
	ListNode* _prev;
};

class LinkedList
{
public:
	ListNode *_head;
	ListNode *_tail;
	int _count;

	LinkedList();
	~LinkedList();

	void PushBack (Trips trip);
	void PushFront (Trips trip);
	
	ListNode* LinkedList::FindInt (int key);
	void Remove (ListNode *key);
	void PrintList();
	
	Trips PopFront();
	Trips PopBack();
};