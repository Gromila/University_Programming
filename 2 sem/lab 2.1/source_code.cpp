#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>

//глобальные переменные
int connections; //количество подключений
int floors=1; //количество этажей
int height; //высота потолков
int width; //толщина перекрытий
int s; //расстояние от точки до шкафа
int length; //длина кабеля
float network; //цена проектирования
int hard; //цена оборудования
float total; //итоговая стоимость

//функции 
char menu();
void connection_number();
void floors_number();
void height_width();
void point();
void total_length();
void total_hardware();
void cost();
void network_cost();
void info();

int main()
{	
	setlocale(LC_CTYPE,"rus");
	while (true)
	{
		switch(menu())
		{
			case '1': connection_number(); break;
			case '2': floors_number(); break;
			case '3': height_width(); break;
			case '4': point(); break;
			case '5': network_cost(); break;
			case '6': total_length(); break;
			case '7': total_hardware(); break;
			case '8': cost(); break;
			case '9': info(); break;
			case '0': return 0;  //Выход из программы
			default: printf("Неправильный ввод данных. Нажмите Enter, чтобы продолжить");
		}
		system("CLS"); //очистка экрана		
	}
}

char menu() // Главное меню
{ 
	printf("Вас приветсвует фирма АМР \n");
	printf("1. Ввод количества подключений (текущее %d) \n",connections);
	printf("2. Ввод количества этажей для подключения (текущее %d) \n",floors);
	printf("3. Ввод высоты этажей и толщины перекрытий (текущее %d, %d) \n",height,width);
	printf("4. Ввод среднего расстояния от точки подключения до распределительного шкафа на этаже (текущее %d) \n",s);
	printf("5. Рассчёт стоимости проектирования сети \n");
	printf("6. Рассчёт общей длины кабеля \n");
	printf("7. Рассчёт стоимости необходимого сетевого оборудования \n");
	printf("8. Рассчёт общей стоимости проекта \n");
	printf("9. Краткая информация о фирме и контакты \n");
	printf("0. Выход из программы \n");
	printf("-------------------------------------------\n");
	int ch=getch();
	return ch;
}

void connection_number()
{
	printf("Введите количество желающих подключиться \n");
	scanf("%d",&connections);
}

void floors_number()
{
	printf("Введите количество этажей \n");
	scanf("%d",&floors);
}

void height_width()
{
	printf("Введите высоту и толщину перекрытий \n");
	scanf("%d%d",&height,&width);
}

void point()
{
	printf("Введите расстояние от точки подключения до шкафа (в метрах) \n");
	scanf("%d",&s);
}

void total_length()
{
	length=s*connections+height*(floors-1)+width*(floors-1);
	printf("Общая длина кабеля %d метров",length);
	getch();
}

void total_hardware()
{
	hard=3*connections+143*floors;
	printf("Стоимость необходимого сетевого оборудования %d$",hard);
	getch();
}

void cost()
{
	total=3*connections+143*floors+1.5*(s*connections+height*(floors-1)+width*(floors-1))+20*(floors-1);
	printf("Итоговая стоимость %f$",total);	
	getch();
}

void network_cost()
{
	network=3*(3*connections+143*floors+1.5*(s*connections+height*(floors-1)+width*(floors-1))+20*(floors-1))/10;
	printf("Стоимость проектирования сети составит %f$",network);
	getch();
}

void info()
{
	printf("Монтажная фирма АМР \n Наш адрес: г. Минск пр. Жукова д.1 оф.1 \n \n Контактные телефоны: \n 211-23-44 \n 603-45-43 (Velcom)\n 703-45-43 (MTS)\n");
	getch();
}