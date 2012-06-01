#include "db.h"

int DB::CreateDB (const char *path)
{
	FILE *fp;
	int result = 1;
	fp = fopen (path, "w+b");
	if (!fp)
		return 0;
	fclose (fp);
	return result;
}

FILE* DB::OpenDB (const char *path)
{
	FILE *fp = fopen (path, "r+b");
/*	if (fp)
		DB::ReadTour(fp, 0, header);*/
	return fp;
}

void DB::ToList (FILE *fp, LinkedList *myList)
{
	fseek(fp, 0, SEEK_SET);
	Trips trip;
	while (fread (&trip, sizeof(Trips), 1, fp))
	{
		myList -> PushBack(trip);
	}
} 

void DB::CloseDB (FILE *fp)
{
	printf("База данных закрывается...");
	system("CLS");
	fclose(fp);
	printf("База данных успешна закрыта");
	getch();
}

void DB::InputTrip (Trips *trip)
{
	trip -> number = 0;
	for (int i = 0; i < strlen (trip -> route); i++)
		trip -> route[i] = ' ';
	trip -> cost = 0;
	trip -> time.day = 0;
	trip -> time.month = 0;
	trip -> time.year = 0;
	trip -> seats = 0;

	while (trip -> number < 1 || trip -> number > 32000)
	{
		printf("\nНовый номер путёвки: ");
		scanf("%d", &trip -> number);
		if (trip -> number < 0 || trip -> number > 32000)
			printf ("Неправильный ввод");
	}
	printf("\nНовый маршрут: ");
	scanf("%s", trip -> route);

	while (trip -> time.day < 1 || trip -> time.day > 31 || trip -> time.month < 1 || trip -> time.month > 12 || trip -> time.year < 2012 || trip -> time.year > 2020)
	{
		printf("\nНовая дата отправления: ");
		scanf("%d.%d.%d", &trip -> time.day, &trip -> time.month, &trip -> time.year);
		if (trip -> time.day < 1 || trip -> time.day > 31 || trip -> time.month < 1 || trip -> time.month > 12 || trip -> time.year < 2012 || trip -> time.year > 2020)
			printf ("Неправильный ввод");
	}
	while (trip -> seats < 1 || trip -> seats > 1000)
	{
		printf("\nНовое кол-во свободных мест: ");
		scanf ("%d", &trip -> seats);
		if (trip -> seats < 0 || trip -> seats > 1000)
			printf ("Неправильный ввод");
	}
	while (trip -> cost < 1 || trip -> cost > 32000)
	{
		printf("\nНовая цена: ");
		scanf ("%d", &trip -> cost);
		if (trip -> cost < 0 || trip -> cost > 32000)
			printf ("Неправильный ввод");
	}
}
