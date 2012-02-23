#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <time.h>
#include <stdlib.h>

int *z, m;

void Massive_Size();
void Massive_Create();
void Massive_Random();
int Max_Number();
void Massive_Print();
void Max_Print();
void Massive_Destroy();

void main()
{
	setlocale(LC_CTYPE,"rus");
	Massive_Size();
	Massive_Create();
	Massive_Random();
	Massive_Print();
	Max_Print();
	Massive_Destroy;
	getch();
}

void Massive_Size()
{
	while (m<1) 
	{
		printf("\nВведите размерность массива\n");
		scanf("%d",&m);
		if (m<1) printf("\nНеверный ввод\n");
	}
}

void Massive_Create()
{
	z = new int [m];
}

void Massive_Random()
{
	srand(static_cast<unsigned>(time(NULL)));
	for (int i = 0; i < m; i++)
		z[i] = 1 + rand()%9;
}

int Max_Number()
{
	int k=1;
	int max = z[0];
	for (int i = 1; i < m; i++)
	{
		if (z[i] > max) 
		{
			k = 0;
			max = z[i];
		}
		if (z[i] == max) k++;
	}
	return k;
}

void Massive_Print()
{
	printf("\n");
	for (int i = 0; i < m; i++)
		printf("%d ",z[i]);
	printf("\n");
}

void Max_Print()
{
	printf("\nКол-во наибольших элементов = %d",Max_Number());
}

void Massive_Destroy()
{
	delete []z;
	z = NULL;
}