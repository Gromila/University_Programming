#include "interface.h"
#include "help.h"

DB db;
LinkedList myList;
FILE *database;
char path[250];

bool IsEqual (char *a, char *b)
{
	if (strlen(a) != strlen(b))
		return false;
	else
	{
		int i = 1;
		while (i < strlen(a))
		{
			if (a[i] != b[i])
				return false;
			i++;
		}
	}
	return true;
}

void Menu()
{
	bool menu = true;
	char key;
	while (menu)
	{
		printf("\nМеню входа:\n1. Меню пользователя\n2. Меню администратора\n3. Выход\n");
		char ch = getch();
		system("CLS");
		switch (ch)
		{
		case 0:
			key = getch();
			if (key == 59)
				MainHelp();
			break;
		case '1':
			UserMenu();
			break;
		case '2':
			AdminCheck();
			break;
		case '3':
			menu = false;
			break;
		case char(27):
			menu = false;
			break;
		default:
			printf("\nОшибка ввода, попробуйте ещё раз");
			break;
		}
	}
}

void MainMenu()
{
	bool menu = true;
	printf("    *@###+\n");
	printf("  .##.   -                         +#:\n");
	printf("  .##.       @#@@###   :#*@#@##- -######  ##@@@##   :#*###- .##@@##.  .#==#@##*\n");
	printf("   .###@:         :#*  :#=    #@   +#:         :#+  :##.   .#=    =#. .##.   =#-\n");
	printf("       :##*  .######+  :#*    @#.  +#:    .######+  :#*    *########: .##    +#:\n");
	printf("        .#@ :#+   :#+  :#*    @#.  +#:   :#+   :#+  :#*    :#*        .##    +#:\n");
	printf("  *##**=##- -#@-.+##+  :#*    @#.  :##.- .#@-.+##+  :#*     +#=-..*=  .##    +#:\n");
	printf("   .::-      .::                    -:.   .::                .:::\n");
	getch();
	system("CLS");
	Menu();
}

void AdminCheck()
{
	char login [128], pass [128];
	printf("Введите логин: ");
	scanf("%s", login);
	printf("\nВведите пароль: ");
	scanf("%s", pass);
	if ((IsEqual(login, "admin")) && (IsEqual(pass,"admin")))
			AdminMenu();
	else
	{
		printf ("Неправильный логин или пароль");
		Menu();
	}
	getch();
	system("CLS");
}

void UserMenu()
{
	bool menu = true;
	int i;
	char key;
	system("CLS");
	while (menu)
	{
		printf("1. Показать расписание\n2. Купить билет\n3. Справка\n4. Возврат в предыдущее меню\n");
		char ch = getch();
		system("CLS");
		switch (ch)
		{
		case 0:
			key = getch();
			if (key == 59)
				UserHelp();
			break;
		case '1':
			myList.PrintList();
			getch();
			break;
		case '2':
			printf("Введите номер тура, который Вы желаете приобрести \n");
			scanf("%d", &i);
			BuyTicket(myList.FindInt(i));
			break;
		case '3':
			printf("Здесь обязательно будет справка!!");
			break;
		case '4':
			menu = false;
			break;
		case char(27):
			menu = false;
			break;
		default:
			printf("Ошибка ввода");
			break;
		}
		system("CLS");
	}
}

void AdminMenu()
{
	Trips *NewTrip = new Trips();
	system("CLS");
	bool menu = true;
	ListNode* p, *p1;
	int i = 0, j = 0;
	char key;
	while (menu)
	{
		system("CLS");
		printf("\n1. Создать новую БД\n2. Открыть существующую БД\n3. Добавить новый тур\n4. Удалить тур\n5. Редактировать тур\n6. Закрыть БД\n7. Вернуться в предыдущее меню\n8. File -> List\n"); 
		char ch = getch();
		system("CLS");
		switch (ch)
		{
		case 0:
			key = getch();
			if (key == 59)
				AdminHelp();
			break;

		case '1':
			printf("Введите адрес к БД\n");
			scanf("%s", path);
			if (db.CreateDB (path))
				printf("База данных успешно создана по адресу: %s", path);
			else
				printf("Fail");
			break;

		case '2':
			printf("Введите адрес к БД\n");
			scanf("%s", path);
			database = db.OpenDB(path);
			system("CLS");
			if (database)
				printf("\nБаза данных %s открыта\n", path);
			else
				printf("\nFail\n");
			getch();
			break;

		case '3':
			db.InputTrip(NewTrip);
			myList.PushBack (*NewTrip);
			myList.PrintList();
			getch();
			break;

		case '4':
			myList.PrintList();
			printf("Введите номер тура, который Вы желаете удалить \n");
			scanf("%d", &i);
			myList.Remove(myList.FindInt(i));
			myList.PrintList();
			getch();
			break;

		case '5':
			myList.PrintList();
			printf("Введите номер тура, который Вы желаете отредактировать \n");
			scanf("%d", &i);
			p = myList.FindInt(i);
			db.InputTrip(&p -> _data);
			printf("\n\n");
			myList.PrintList();
			getch();
			break;

		case '6':
			p = myList._head;
			database = db.OpenDB(path);
			fseek (database, 0, SEEK_SET);
			while (p)
			{
				fwrite (&p->_data, sizeof(Trips), 1, database);
				p1 = p;
				p = p -> _next;
				myList.Remove (p1);
			}
			db.CloseDB(database);
			break;

		case '7':
			menu = false;
			break;
	
		case '8':
			db.ToList(database, &myList);
			myList.PrintList();
			fclose (database);
			getch();
			break;
		
		case char(27):
			menu = false;
			break;
		default:
			printf ("Неправильный ввод");
			break;
		}
	}
}