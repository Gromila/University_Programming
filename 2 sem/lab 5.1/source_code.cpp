#include <stdio.h>
#include <allocators>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <clocale>

typedef struct TItem
{
	int _Digit;
	struct TItem *next;
	struct TItem *prev;
}	Item;

typedef struct TLongNumber
{
	Item *head;
	Item *tail;
	int n;
	bool minus;
}	LongNumber;

void Menu();
LongNumber Addition (LongNumber a, LongNumber b);
LongNumber Subtract (LongNumber a, LongNumber b);
LongNumber Multiply (LongNumber a, LongNumber b);
LongNumber Division (LongNumber a, LongNumber b);
LongNumber CreateLN (char *initStr);
void AddDigit (LongNumber *number, int digit);
void AddDigitFirst (LongNumber *number, int digit);
void PrintLN (LongNumber number);
LongNumber LongSumLong (LongNumber n1, LongNumber n2); //сумма без учёта знаков
LongNumber Copy (LongNumber n1);
LongNumber LongSubLong (LongNumber n1, LongNumber n2); //первое больше второго!
LongNumber LongMulLong (LongNumber n1, LongNumber n2); //большее на меньшее!
LongNumber LongMulShort (LongNumber n, int x);
int AmoreB (LongNumber n1, LongNumber n2); //1 если n1 > n2, -1 если n2 > n1; иначе 0;
LongNumber CreateTemp (LongNumber n1, LongNumber n2);
LongNumber LongDivLong (LongNumber A, LongNumber B);
int TmoreB (LongNumber n1, LongNumber n2); //AmoreB без учёта минуса.
int FindC (LongNumber A1, LongNumber B); //от 1 до 9 - множитель;
void DeleteLN (LongNumber a);

Item *pointer;


void main()
{
	setlocale(LC_CTYPE,"rus");
	bool menu = true;
	char str[128];
	LongNumber a, b, Result;
	while (menu)
	{
		Menu();
		char ch = getch();
		system("CLS");
		switch (ch)
		{
		case '1':
			gets(str);
			a = CreateLN(str);
			break;
		case '2':
			gets(str);
			b = CreateLN(str);
			break;
		case '3':
			Result = Addition(a,b);
			PrintLN(Result);
			break;
		case '4':
			Result = Subtract (a,b);
			PrintLN(Result);
			break;
		case '5':
			Result = Multiply (a,b);
			PrintLN(Result);
			break;
		case '6':
			Result = Division (a,b);
			PrintLN(Result);
			break;
		case '7':
			PrintLN(a);
			break;
		case '8':
			PrintLN(b);
			break;
		case '0':
			menu = false;
			break;
		default:
			printf("Incorrect input");
			break;
		}
		printf("\n");
	}
	if (a.head != NULL)
		DeleteLN(a);
	if (b.head != NULL)
		DeleteLN(b);
	if (Result.head != NULL)
		DeleteLN(Result);
}

void Menu()
{
	printf("1. Ввод первого числа\n");
	printf("2. Ввод второго числа\n");
	printf("3. Сумма\n");
	printf("4. Разность\n");
	printf("5. Произведение\n");
	printf("6. Частное\n");
	printf("7. Вывести первое\n");
	printf("8. Вывести второе\n");
	printf("0. Exit\n");
}

LongNumber Addition (LongNumber a, LongNumber b)
{
	LongNumber Add = CreateLN("");
	if ((a.minus) && (!b.minus))
	{
		if (TmoreB(a,b) == 1)
		{
			Add = LongSubLong(Copy(a),b);
			Add.minus = true;
		}
		if (TmoreB(a,b) == 0)
		{
			AddDigit(&Add,0);
			Add.minus = false;
		}
		if (TmoreB(a,b) == -1)
		{
			Add = LongSubLong(Copy(b),a);
			Add.minus = false;
		}
	}
	if ((!a.minus) && (!b.minus))
		if ((TmoreB(a,b) == 1) || (TmoreB(a,b) == -1))
		{
			Add = LongSumLong(a,b);
			Add.minus = false;
		}
		else
		{
			Add = LongMulShort(a,2);
			Add.minus = false;
		}
	if ((a.minus) && (b.minus))
	{
		if ((TmoreB(a,b) == 1) || (TmoreB(a,b) == -1))
			Add = LongSumLong(a,b);
		else
			Add = LongMulShort(a,2);
		Add.minus = true;
	}
	if ((!a.minus) && (b.minus))
	{
		if (TmoreB(a,b) == 1)
		{
			Add = LongSubLong(Copy(a),b);
			Add.minus = false;
		}
		if (TmoreB(a,b) == -1)
		{
			Add = LongSubLong(Copy(b),a);
			Add.minus = true;
		}
		if (TmoreB(a,b) == 0)
		{
			AddDigit(&Add,0);
			Add.minus = false;
		}
	}
	return Add;
}

LongNumber Subtract (LongNumber a, LongNumber b)
{
	LongNumber Sub = CreateLN("");
	if ((!a.minus) && (!b.minus))
	{
		if (TmoreB(a,b) == 1)
		{
			Sub = LongSubLong(Copy(a),b);
			Sub.minus = false;
		}
		if (TmoreB(a,b) == -1)
		{
			Sub = LongSubLong(Copy(b),a);
			Sub.minus = true;
		}
		if (TmoreB(a,b) == 0)
		{
			AddDigit(&Sub,0);
			Sub.minus = false;
		}
	}
	if ((!a.minus) && (b.minus))
	{
		if (TmoreB(a,b) == 1)
			Sub = LongSumLong(a,b);
		else if (TmoreB(a,b) == -1)
				Sub = LongSumLong(b,a);
			 else
				Sub = LongMulShort(a,2);
		Sub.minus = false;
	}
	if ((a.minus) && (!b.minus))
	{
		if ((TmoreB(a,b) == 1) || (TmoreB(a,b) == -1))
		{
			Sub = LongSumLong(a,b);
			Sub.minus = true;
		}
		else
		{
			Sub.minus = false;
			Sub = LongMulShort(a,2);
		}
	}
	if ((a.minus) && (b.minus))
	{
		if (TmoreB(a,b) == 1)
		{
			Sub = LongSubLong(Copy(a),b);
			Sub.minus = true;
		}
		if (TmoreB(a,b) == 0)
		{
			AddDigit(&Sub,0);
			Sub.minus = false;
		}
		if (TmoreB(a,b) == -1)
		{
			Sub = LongSubLong(Copy(b),a);
			Sub.minus = false;
		}
	}
	return Sub;
}

LongNumber Multiply (LongNumber a, LongNumber b)
{
	LongNumber Mul = CreateLN("");
	if (TmoreB(a,b) == -1)
	{
		if (((!a.minus) && (!b.minus))||((a.minus) && (b.minus)))
			Mul.minus = false;
		else 
			Mul.minus = true;
		Mul = LongMulLong(b,a);
	}
	else
	{
		Mul = LongMulLong(a,b);
		if (((!a.minus) && (!b.minus))||((a.minus) && (b.minus)))
			Mul.minus = false;
		else Mul.minus = true;
	}
	return Mul;
}

LongNumber Division (LongNumber a, LongNumber b)
{
	LongNumber Div = CreateLN("");
	if (((!a.minus) && (b.minus)) || ((a.minus) && (!b.minus)))
		Div.minus = true;
	else 
		Div.minus = false;
	if (TmoreB(a,b) == -1)
	{
		AddDigit(&Div,0);
		Div.minus = false;
	}
	if (TmoreB(a,b) == 0)
		AddDigit(&Div,1);
	if (TmoreB(a,b) == 1)
		Div = LongDivLong(a,b);
	return Div;
}

LongNumber CreateLN (char initStr[])
{
	LongNumber number = {NULL,NULL,0,0};
	int i = strlen(initStr)-1;
	if (initStr[0] == '-') 
	{
		number.minus = 1;
		for (; i>=1; i--)
			AddDigit(&number, initStr[i]-'0');
	}
	else 
	{
		number.minus = 0;
		for (; i>=0; i--)
			AddDigit(&number, initStr[i]-'0');
	}
	return number;
}

void AddDigit(LongNumber *number, int digit)
{
	Item *p = (Item *)malloc(sizeof(Item));
	p->_Digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail=p;
	}
	number->n++;
}

void AddDigitFirst (LongNumber *number, int digit)
{
	Item *p = (Item *)malloc(sizeof(Item));
	p->_Digit = digit;
	p->next = p->prev = NULL;
	if (number->tail == NULL)
		number->tail = number->head = p;
	else
	{
		number -> head ->prev = p;
		p->next = number -> head;
		number -> head = p;
	}
	number->n++;
}

LongNumber LongSumLong (LongNumber n1, LongNumber n2)
{
	LongNumber sum = CreateLN("");
	Item *p1 = n1.head, *p2 = n2.head;
	int digit, pos = 0, s1, s2;
	while (p1 || p2)
	{
		if (p1) 
		{
			s1 = p1->_Digit;
			p1 = p1->next;
		}
		else s1 = 0;
		if (p2)
		{
			s2 = p2->_Digit;
			p2 = p2->next;
		}
		else s2 = 0;
		digit = (s1+s2+pos)%10;
		pos = (s1+s2+pos)/10;
		AddDigit(&sum,digit);
	}
	if (pos) AddDigit(&sum,pos);
	return sum;
}

void PrintLN(LongNumber number)
{
	Item *p = number.tail;
	printf("\nNumber: ");
	if (number.minus) printf("-");
	while (p)
	{
		printf("%d", p->_Digit);
		p = p->prev;
	}
}

LongNumber Copy (LongNumber n1)
{
	LongNumber nNew = CreateLN("");
	nNew.minus = n1.minus;
	nNew.n = n1.n;
	Item *p = n1.head;
	while (p)
	{
		AddDigit(&nNew, p->_Digit);
		p = p->next;
	}
	return nNew;
}

LongNumber LongSubLong (LongNumber n1, LongNumber n2)
{
	LongNumber Sub = CreateLN("");
	Item *p1 = n1.head;
	Item *p2 = n2.head;
	int d1, d2, digit;
	while (p1||p2)
	{
		if (p1)
		{
			d1 = p1->_Digit;
			p1 = p1->next;
		}
		else d1 = 0;
		if (p2)
		{
			d2 = p2->_Digit;
			p2 = p2->next;
		}
		else d2 = 0;
		if (d1 < d2) 
		{
			d1 += 10;
			p1->_Digit -= 1;
		}
		digit = d1 - d2;
		AddDigit(&Sub,digit);
	}
	while ((Sub.tail->_Digit == 0) && (Sub.n > 1))
	{
		Sub.tail = Sub.tail->prev;
		Sub.tail->next = NULL;
		Sub.n--;
	}
	return Sub;
}

LongNumber LongMulLong (LongNumber n1, LongNumber n2)
{
	LongNumber Mul = CreateLN("");
	int d1, d2, digit, i = 1, pos = 0;
	Item *p2 = n2.head;
	while (p2)
	{
		Item *p1 = n1.head;
		LongNumber Temp = CreateLN("");
		d2 = p2->_Digit;
		int j = 1;
		while (j < i)
		{
			AddDigit(&Temp,0);
			j++;
		}
		while (p1)
		{
			d1 = p1->_Digit;
			p1 = p1->next;
			digit = (d1*d2+pos)%10;
			pos = (d1*d2+pos)/10;
			AddDigit(&Temp, digit);
		}
		if (pos) AddDigit(&Temp, pos);
		pos = 0;
		p2 = p2->next;
		Mul = LongSumLong(Mul, Temp);
		i++;
	}
	if ((n1.minus) && (!n2.minus)) Mul.minus = 1;
	if ((!n1.minus) && (n2.minus)) Mul.minus = 1;
	return Mul;
}

LongNumber LongMulShort (LongNumber n, int x) //умножение на число от 1 до 9
{
	LongNumber mul = CreateLN("");
	Item *p = n.head;
	int pos = 0, s, digit;
	while (p)
	{
		s = p->_Digit;
		p = p->next;
		digit = (s*x+pos)%10;
		pos = (pos+s*x)/10;
		AddDigit(&mul,digit);
	}
	if (pos) AddDigit(&mul,pos);
	if (n.minus) mul.minus = 1;
	return mul;
}

int AmoreB (LongNumber n1, LongNumber n2)
{
	if ((n1.minus) && (!n2.minus))
		return -1;
	if ((!n1.minus) && (n2.minus))
		return 1;
	if (n1.n > n2.n)
		if ((n1.minus) && (n2.minus))
			return -1;
		else return 1;
	else if (n1.n < n2.n)
			if ((n1.minus) && (n2.minus))
				return 1;
			else return -1;
		 else
		 {
			 Item *p1 = n1.tail;
			 Item *p2 = n2.tail;
			 int s1, s2;
			 while (p1 && p2)
			 {
				 s1 = p1->_Digit;
				 p1 = p1->prev;
				 s2 = p2->_Digit;
				 p2 = p2->prev;
				 if (s1 > s2) return 1;
				 if (s2 > s1) return -1;
			 }
			 return 0;
		 }
}

LongNumber CreateTemp (LongNumber n1, LongNumber n2)
{
	LongNumber Temp = CreateLN("");
	Item *p = n1.tail;
	int i = 0;
	while (i < n2.n)
	{
		AddDigitFirst (&Temp, p->_Digit);
		p = p->prev;
		i++;
	}
	pointer = p;
	if (TmoreB(n2, Temp) == 1) AddDigitFirst (&Temp, p->_Digit);
	return Temp;
}

int FindC (LongNumber A1, LongNumber B)
{
	LongNumber B1 = Copy(B);
	int C = 0;
	while ((TmoreB(A1,LongMulShort(B1,C)) == 1) || (TmoreB(A1, LongMulShort(B1,C)) == 0))
		C++;
	C--;
	return C;
}

LongNumber LongDivLong (LongNumber A, LongNumber B)
{
	LongNumber Div = CreateLN ("");
	while ((TmoreB(A,B) == 1) || (TmoreB(A,B) == 0))
	{
		LongNumber A1 = CreateTemp(A,B);
		int C = FindC(A1,B);
		AddDigitFirst(&Div,C);
		LongNumber CB = LongMulShort(B,C);
		int zero = A.n - A1.n;
		while (zero > 0)
		{
			AddDigitFirst(&CB,0);
			zero--;
		}
		if (TmoreB(CB,A) == 0) 
		{
			zero = A.n - A1.n;
			while (zero > 0)
			{
				AddDigitFirst(&Div,0);
				zero--;
			}
		}
		while ((pointer != NULL) && (pointer->_Digit == 0))
		{
			AddDigitFirst(&Div,0);
			pointer = pointer->prev;
		}
		A = LongSubLong(A,CB);
	}
	return Div;
}

int TmoreB (LongNumber n1, LongNumber n2)
{
	Item *p1 = n1.tail;
	Item *p2 = n2.tail;
	if (n1.n > n2.n) return 1;
	if (n1.n < n2.n) return -1;
	while (p1 && p2)
	{
		if (p1->_Digit > p2->_Digit) return 1;
		if (p1->_Digit < p2->_Digit) return -1;
		p1 = p1->prev;
		p2 = p2->prev;
	}
	return 0;
}

void DeleteLN (LongNumber a)
{
	Item *p;
	while (a.head != NULL)
	{
		p = a.head;
		a.head = a.head->next;
		free (p);
	}
}