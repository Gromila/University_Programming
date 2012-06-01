#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <stdlib.h>

const int N = 3;

int max_length = 0; // максимальная длина строки
char *strings[N]; //3 строки

void string_maxlength ();
int string_length (const char* str);
void string_insert (char* str, char st, int i); // (куда; что; в какое место)
void add_space (char* str, int length);
void string_copy (const char* str1, char* str2); // (откуда, куда)
void strings_delete();

void main()
{
	setlocale(LC_CTYPE,"rus");
	printf("Введите текст (длина %d строк)\n",N);
	char buffer[128];
	for (int i = 0; i < N; i++)
	{
		gets(buffer);
		strings[i] = new char [string_length(buffer)];
		string_copy(buffer,strings[i]);
	}
	printf("\nВыравнивание по ширине относительно самой длинной строки:\n");
	string_maxlength();
	for (int i = 0; i < N; i++)
	{
		add_space (strings[i], string_length(strings[i]));
		puts(strings[i]);
	}
	getch();
}

void string_maxlength()
{
	for (int i = 0; i < N; i++)
	{
		int k = string_length(strings[i]);
		if (max_length < k)
			max_length = k;
	}
}

int string_length (const char* str)
{
	int i = 0;
	while (str[i]!=NULL)
		i++;
	return i;
}

void string_insert (char* str, char st, int i)
{
	int k = string_length(str);
	for (int j=k;j>=i-1;j--)
		str[j+1]=str[j];
	str[i-1]=st;
}

void add_space (char* str, int length)
{
	int max_spaces = max_length - length; //счётчик недостающих пробелов
	int i=0;
	int spaces=0;
	int spaces_left=0;
	while (i!=length)
	{
		if (str[i]==' ') spaces++;
		i++;
	}
	if (spaces != 0) 
	{
		int k = max_spaces/spaces; //кол-во пробелов на промежуток
		spaces_left = max_spaces % spaces;
		for (i = 0; i<=max_length; i++)
		{
			if (max_spaces != 0)
				if (str[i]==' ') 
					for (int j=1; j<=k; j++)
					{
						string_insert(str,' ',i+1);
						i++;
					}
		}
	}
	i = string_length(str);
	if (i < max_length)
	{
		while (str[i]!=' ') i--;
		while (spaces_left != 0)
		{
			string_insert(str,' ',i+1);
			spaces_left--;
		}

	}
}

void string_copy (const char* str1, char* str2)
{
	int i = 0;
	while (str1[i]!='\0')
	{
		str2[i]=str1[i];
		i++;
	}
	str2[i]='\0';
}