#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>

using namespace std;

typedef struct item
{
	char data;
	struct item *left;
	struct item *right;
} Item;

int all;
int reply;
int nodes;

void AddNode (char data, Item **node);
void PrintLeft (Item *node);
Item *SearchItem (char key, Item *node);
void NodeNumber (Item *node);
void Output (Item *node, int k);
void Delete (Item *node);

void main()
{
	setlocale (LC_CTYPE, "rus");
	char *text;
	char buffer[128];
	Item *root = NULL;	
	printf("Введите строку\n");
	gets(buffer);
	text = new char[strlen(buffer)];
	strcpy(text, buffer);
	puts(text);
	int i = 0;
	while (text[i]!='\0')
	{
		AddNode (text[i], &root);
		i++;
	}
	PrintLeft (root);
	printf("\nКол-во повторяющихся элементов: %d\n", reply);
	char letter;
	Item *point;
	printf("\nВведите нужный символ\n");
	scanf("%c",&letter);
	point = SearchItem(letter, root);
	if (point != NULL) 
	{
		NodeNumber(point);
		printf("\nКол-во узлов дерева: %d\n", nodes);
	}
	else printf("Not Found");
	Output (root, all);
	Delete (root);
	getch();
}

void AddNode (char data, Item **node)
{
	all++;
	if (*node == NULL)
	{
		*node = (Item *)calloc(1,sizeof(Item));
		(*node)->data = data;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
	else
	{
		if (data < (*node)->data)
			AddNode (data, &(*node)->left);
		else if (data > (*node)->data)
			AddNode (data, &(*node)->right);
		else reply++;
	}
}

void PrintLeft (Item *node)
{
	if (node->left)
		PrintLeft (node->left);
	printf("%c\n", node->data);
	if (node->right)
		PrintLeft (node->right);
}

Item *SearchItem (char key, Item *node)
{
	if (key < node->data) 
		if (node->left) 
			SearchItem (key, node->left);
		else
		у	return NULL;
	else 
	if (key > node->data) 
		if (node->right) 
			SearchItem (key, node->right);
		else 
			return NULL;
	else 
	if (key == node->data) return node;
}

void NodeNumber (Item *node)
{
	if (node->left)
	{
		nodes++;
		NodeNumber(node->left);
	}
	if (node->right)
	{
		nodes++;
		NodeNumber(node->right);
	}
}

void Output (Item *node, int k)
{
	if (node != NULL)
	{
		Output (node->left, k-3);
		for (int i = 0; i < k; i++)
			printf("-");
		printf("%c\n",node->data);
		Output (node->right, k-3);
	}
}

void Delete (Item *node)
{
	if (node->left != NULL)
		Delete(node->left);
	if (node->right != NULL)
		Delete(node->right);
	free(node);
}