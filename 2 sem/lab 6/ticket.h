#include "db.h"

typedef struct customer
{
	char surname [30];
	int passport;
	char address [30];
	int phone;
} Customer;

void BuyTicket (ListNode* trip);