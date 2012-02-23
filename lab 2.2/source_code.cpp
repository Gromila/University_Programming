#include <stdio.h>
#include <conio.h>
#include <math.h>

double m;
double x;

void input();
double factorial (int n);
double c_recursion (double j);
double c_standart (int j);
double binom_standart();
double binom_recursion();
void output (double result);

void main()
{
	input();
	output(binom_standart());
	output(binom_recursion());
	getch();
}

void input()
{
	printf("m = ?, x = ?\n");
	scanf("%lf%lf",&m,&x);
}

double factorial (int n)
{
	if (n==1 || n==0) return 1;
	else return n*factorial(n-1);
}

double c_recursion (double j)
{
	if (j==0) return 1;
	else return ((m-j+1)/(j))*c_recursion(j-1);
}

double c_standart (int j)
{
	return factorial(m)/(factorial(j)*factorial(m-j));
}

double binom_standart()
{
	float s=0;
	for (int i = 0; i<=m; i++)
		s += c_standart(i)*pow(x,i);
	return s;
}

double binom_recursion()
{
	float s=0;
	for (int i = 0; i<=m; i++)
		s += c_recursion(i)*pow(x,i);
	return s;
}

void output (double result)
{
	printf("\nResult = %.1lf\n", result);
}