#include <stdio.h>
#include <allocators>
#include <conio.h>
#include <clocale>
#include <stdlib.h>


#define N 128

void Error(const char *message);
void WordToSet();
void DeleteChar(int i, char* str);
bool CharInSet(char s);
int string_length (const char* str);

char word[N];

void main()
{
	int k;
	setlocale(LC_CTYPE,"rus");
	FILE *fp;
	char buffer[N];
	fp = fopen("file.txt","r");
	if(!fp)
		Error("Opening file");
	printf("Введите слово\n");
	gets(word);
	printf("\n\n");
	WordToSet(); //удаляю из слова повторяющиеся символы
	while(fgets(buffer,N,fp) != NULL)
	{
		for (int i = 0; i < string_length (buffer)-1; i++)
		{
			if (!CharInSet(buffer[i]))
			{
				k = 0;
				break;
			}
			else k = 1;
		}
		if (k) puts(buffer);
	}
	fclose(fp);
	system("pause");
}

void Error (const char *message)
{
	printf("\n\nError: %s\n\n", message);
}

void WordToSet()
{
	int k = string_length(word);
	int i = 0, j = 1;
	while (i < k)
	{
		while (j < k)
		{
			if (word[i] == word[j]) 
			{
				DeleteChar (j,word);
				k = string_length(word);
			}
			else j++;
		}
		i++;
		j = i + 1;
	}

}

void DeleteChar(int i, char* str)
{
	for (int j = i; j < string_length(str); j++)
		str[j]=str[j+1];
	str[string_length(str)]='\0';
}

bool CharInSet(char s)
{
	for (int i = 0; i < string_length (word); i++)
		if (s == word[i]) return 1;
	return 0;
}

int string_length (const char* str)
{
	int i = 0;
	while (str[i]!=NULL)
		i++;
	return i;
}