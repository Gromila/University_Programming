#include <stdio.h>
#include <conio.h>
#include <clocale>

float p,k,t;

void input ();
int age ();
void output (int year);

void main()
{
	setlocale(LC_CTYPE,"rus");
	input();
	int j = age();
	if (j!=-1) output(j);
	getch();
}

void input ()
{
	while (p<=0)
	{
		printf("\nПервоначальный объём древесины = ");
		scanf("%f",&p);
		if (p<=0) printf("\nНеправильный ввод\n");
	}
	while (k<=0)
	{
		printf("\nЕжегодный прирост = ");
		scanf("%f",&k);
		if (k<=0) printf("\nНеправильный ввод\n");
	}
	while (t<=0)
	{
		printf("\nГодовой план заготовки = ");
		scanf("%f",&t);
		if (t<=0) printf("\nНеправильный ввод\n");
	}
}

int age()
{
	int i = 0;
	if ((p-t)*(1+k/100) > p) 
		{
			printf ("\nНикогда\n");
			return -1;
		}
	else
		while (p>0) 
		{
			p -= t;
			p += p*k/100;
			if (p<0) break;
			i++;
		}
	return i;
}

void output (int year)
{
	printf("\nВ бывшем лесу будут расти одни опята через %d лет",year);
}