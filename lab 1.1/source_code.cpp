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
		printf("\n�������������� ����� ��������� = ");
		scanf("%f",&p);
		if (p<=0) printf("\n������������ ����\n");
	}
	while (k<=0)
	{
		printf("\n��������� ������� = ");
		scanf("%f",&k);
		if (k<=0) printf("\n������������ ����\n");
	}
	while (t<=0)
	{
		printf("\n������� ���� ��������� = ");
		scanf("%f",&t);
		if (t<=0) printf("\n������������ ����\n");
	}
}

int age()
{
	int i = 0;
	if ((p-t)*(1+k/100) > p) 
		{
			printf ("\n�������\n");
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
	printf("\n� ������ ���� ����� ����� ���� ����� ����� %d ���",year);
}