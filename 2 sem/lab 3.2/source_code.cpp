#include <stdio.h>
#include <conio.h>
#include <clocale>

//глобальные переменные
int **massive;
int m,n;

// функции
void massive_size();
void massive_initialisation();
void spiral();
void massive_output();
void massive_delete();

void main()
{
	setlocale(LC_CTYPE,"rus");
	massive_size();
	massive_initialisation();
	spiral();
	massive_output();
	getch();
	massive_delete();
}

void massive_size()
{
	printf("Введите размерность массива MxN \n");
	scanf("%d%d",&m,&n);
}

void massive_initialisation()
{
	massive = new int*[m];
	for (int i = 0; i<m; i++)
		massive[i] = new int[n];
}

void spiral()
{
	int i=1,j=0,k=0; //i - числа от 1 до m*n; j - рабочий счётчик
	while (i<=m*n) 
	{
		k++;   //счётчик отступов
		for (j=k-1;j<n-k+1;j++) //верхняя горизонталь
		    massive[k-1][j]=i++;
		if (i>m*n) break;
		for (j=k;j<m-k+1;j++) //правая вертикаль
			massive[j][n-k]=i++;
		if (i>m*n) break;
		for (j=n-k-1;j>=k-1;j--) //нижняя горизонталь
			massive[m-k][j]=i++;
		if (i>m*n) break;
		for (j=m-k-1;j>=k;j--) //левая вертикаль
			massive[j][k-1]=i++;
	}
}

void massive_output()
{
	for (int i=0; i<=m-1; i++)
	{
		printf("\n");
		for (int j=0; j<=n-1; j++)
			printf("%3d ",massive[i][j]);
	}
}

void massive_delete()
{
	for (int i=0; i<m; i++)
		delete []massive[i];
	delete []massive;
	massive = NULL;
}