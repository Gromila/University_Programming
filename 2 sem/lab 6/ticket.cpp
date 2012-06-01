#include "ticket.h"

void BuyTicket (ListNode* trip)
{
	system("CLS");
	FILE *fp = fopen ("tickets.txt", "r+");
	fseek (fp, 0, SEEK_END);
	Customer person;
	printf("\nВведите фамилию ");
	cin >> person.surname;
	printf("\nВведите номер паспорта ");
	cin >> person.passport;
	printf("\nВведите свой адрес ");
	cin >> person.address;
	printf("\nВведите контактный телефон ");
	cin >> person.phone;
	trip -> _data.seats--;
	fprintf(fp, "\n");
	fprintf(fp, "%s ", person.surname);
	fprintf(fp, "%d ", person.passport);
	fprintf(fp, "%s ", person.address);
	fprintf(fp, "%d", person.phone);
	fclose (fp);
	printf("Билет успешно куплен");
	getch();
}