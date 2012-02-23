#include <stdio.h>
#include <conio.h>

int n;
float s;

void enter();
float summa();
int factorial(int a);

void main()
{
	enter();
	printf("\nResult = %f \n",summa());
	getch();
}

void enter()
{
	while (n<=0)
	{
		printf("Vvedite N>0 \n");
		scanf("%d",&n);
		if (n<=0) printf("\nNepravil'nii vvod\n");
	}
}

float summa()
{
	for (int i=1;i<=n;i++)
		for (int j=1; j<=i; j++)
		{
			float p = 1;
			p*=factorial(j+i)/factorial(i);
			s+=p;
		}
	return s;
}

int factorial(int a)
{
	if (a==0 || a==1) return 1;
	else return a*factorial(a-1);
}