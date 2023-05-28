#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Objects.h"
#include "Maze.h"

using namespace std;

void ramka(HANDLE h, int width, int height, string Maze[], int color) {

	SetConsoleTextAttribute(h, color); // установка цвета, которым рисуется рамка поля
	for (int y = 0; y < height; y++) // стандартный двойной цикл на отрисовку рамки
	{
		for (int x = 0; x < width + 32; x++)
		{
			char s;
			if (Maze[y][x] == 'C') // в верхнем левом углу поля - символ соответствующего угла
				s = 218;
			else if (Maze[y][x] == 'S') // нижний левый угол
				s = 192;
			else if (Maze[y][x] == 'L') // нижний левый угол
				s = 76;
			else if (Maze[y][x] == 'E') // нижний левый угол
				s = 69;
			else if (Maze[y][x] == 'V') // нижний левый угол
				s = 86;
			else if (Maze[y][x] == '1') // нижний левый угол
				s = 49;
			else if (Maze[y][x] == '2') // нижний левый угол
				s = 50;
			else if (Maze[y][x] == '3') // нижний левый угол
				s = 51;
			else if (Maze[y][x] == 'D') // верхний правый угол
				s = 191;
			else if (Maze[y][x] == 'K') // нижний правый угол
				s = 217;
			else if (Maze[y][x] == 'A') // верхняя и нижняя граница поля
				s = 196;
			else if (Maze[y][x] == 'B') // левая и правая граница поля
				s = 179;
			else s = ' '; // во всех остальных случаях должен быть просто пробел (означает пустую область поля)
			putchar(s); // выводим символ
		}
		cout << endl;
	}
}

int main()
{
	SetConsoleOutputCP(1251);

	int p;
	const int height1 = 15;//размер карты высота
	const int width1 = 40;//размер карты ширина 
	const int height2 = 20;//размер карты высота
	const int width2 = 45;//размер карты ширина 
	const int height3 = 20;//размер карты высота
	const int width3 = 50;//размер карты ширина 

	cout << "Привет, это игра Лиса и Заяц!" << endl;
	Sleep(1000);
	cout << "Расскажу о правилах: " << "\n 1. Ты, играя за зайца, должен добраться до цели - x, избегая встречи с лисой."
		<< "\n 2. Учти, что лиса умеет быстро бегать, поэтому, если для нее нет препятствий - она тебя съест!"
		<< "\n 3. Не торопись, и подумай, как можно запутать лису." << endl;
	Sleep(10000);
	cout << "Это всё! Нажми 1, если готов начать" << endl;
	cin >> p;
	if (true) 
	{
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // создание хендла потока вывода
		COORD c; // объект для хранения координат
		CONSOLE_CURSOR_INFO cci = { sizeof(char), false }; // создание параметров на отображение курсора
		int color = 1;
		SetConsoleOutputCP(866);
		ramka(h, width1, height1, Maze1, color);

		int dx = 0, dy = 0; // создание смещений по осям для движения 
		int xRabbit = 1, yRabbit = 13;
		int xFox = 1, yFox = 1;
		int xPurpose = 38, yPurpose = 13;


		char purpose = 'x';

		c.X = xRabbit; // связываем объект координат с позициями зайца
		c.Y = yRabbit;

		SetConsoleOutputCP(65001);
		SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
		SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
		cout << u8"\u020D"; // отображаем символ зайца

		c.X = xPurpose; // связываем объект координат с позициями зайца
		c.Y = yPurpose;

		SetConsoleCursorPosition(h, c); // отправляем курсор на позицию цели
		SetConsoleTextAttribute(h, 4); // устанавливаем красный цвет для отрисовки цели
		putchar(purpose); // отображаем символ цели

		Objects objects = Objects(xRabbit, yRabbit, xFox, yFox, 0, 0, 0, 0, 0, 0, 0, 0, 49, 19);

		bool temp = false;
		bool flag = true; // переменная для управления ходом цикла


		while (flag)
		{
			if (_kbhit())
			{
				Sleep(10); // задержка потока программы на заданный интервал
				int k = _getch(); // считываем код клавиши из буфера
				if (k == 0 || k == 224) // если первый код - вспомогательный, считываем второй код
					k = _getch();
				switch (k) // пропускаем код нажатой клавиши внутрь оператора выбора
				{
				case 80: // если была нажата клавиша вниз
					objects.runDown(xRabbit, yRabbit, Maze1);
					break;
				case 72: // если вверх
					objects.runUp(xRabbit, yRabbit, Maze1);
					break;
				case 75: // если влево
					objects.runLeft(xRabbit, yRabbit, Maze1);
					break;
				case 77: // если вправо
					objects.runRight(xRabbit, yRabbit, Maze1);
					break;
				case 27: // если была нажата клавиша ESC
					flag = false; // устанавливаем флажок на ЛОЖЬ, чтоб закончить показ движения
					break;
				}
				objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze1);
			}

			if (xRabbit == 0 || xRabbit == width1 - 1 || yRabbit == 0 || yRabbit == height1 - 1) // проверка на достижение границ поля
			{
				flag = false; // пока что - просто установка управляющей переменной цикла
			}
			else {
				Sleep(100);
				if (xRabbit == xFox and yRabbit == yFox)// проверка на достижение границ поля
				{
					system("cls");
					cout << "you lose((";
					break;
				}
				else if (xRabbit == xPurpose and yRabbit == yPurpose)// проверка на достижение границ поля
				{
					system("cls");
					cout << "you won))";
					temp = true;
					break;
				}
				else objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze1);
			}
		}
		bool temp1 = false;

		if (temp)
		{
			system("cls");
			SetConsoleOutputCP(866);
			ramka(h, width2, height2, Maze2, 9);
			int xRabbit = 1, yRabbit = 18;
			int xFox = 3, yFox = 2;
			int xFox1 = 43, yFox1 = 3;
			int xFox2 = 43, yFox2 = 13;
			int xPurpose = 43, yPurpose = 1;

			char purpose = 'x';


			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;

			SetConsoleOutputCP(65001);
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D"; // отображаем символ зайца

			c.X = xPurpose; // связываем объект координат с позициями "яблока"
			c.Y = yPurpose;

			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию цели
			SetConsoleTextAttribute(h, 4); // устанавливаем красный цвет для отрисовки цели
			putchar(purpose); // отображаем символ цели

			Objects objects = Objects(xRabbit, yRabbit, xFox, yFox, yFox1, xFox1, yFox2, xFox2, 0, 0, 0, 0, 40, 15);

			bool flag = true; // переменная для управления ходом цикла


			while (flag)
			{
				if (_kbhit())
				{
					Sleep(10); // задержка потока программы на заданный ранее интервал
					int k = _getch(); // считываем код клавиши из буфера
					if (k == 0 || k == 224) // если первый код - вспомогательный, считываем второй код
						k = _getch();
					switch (k) // пропускаем код нажатой клавиши внутрь оператора выбора
					{
					case 80: // если была нажата клавиша вниз
						objects.runDown(xRabbit, yRabbit, Maze2);
						break;
					case 72: // если вверх
						objects.runUp(xRabbit, yRabbit, Maze2);
						break;
					case 75: // если влево
						objects.runLeft(xRabbit, yRabbit, Maze2);
						break;
					case 77: // если вправо
						objects.runRight(xRabbit, yRabbit, Maze2);
						break;
					case 27: // если была нажата клавиша ESC
						flag = false; // устанавливаем флажок на ЛОЖЬ, чтоб закончить показ движения
						break;
					}
					objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze2);
					objects.moveFox(xRabbit, yRabbit, xFox1, yFox1, Maze2);
					objects.moveFox(xRabbit, yRabbit, xFox2, yFox2, Maze2);
				}

				if (xRabbit == 0 || xRabbit == width2 - 1 || yRabbit == 0 || yRabbit == height2 - 1) // проверка на достижение границ поля
				{
					flag = false; // пока что - просто установка управляющей переменной цикла
				}
				else {
					Sleep(100);
					if ((xRabbit == xFox and yRabbit == yFox) or (xRabbit == xFox1 and yRabbit == yFox1) or (xRabbit == xFox2 and yRabbit == yFox2))// проверка на достижение границ поля
					{
						system("cls");
						cout << "you lose((";
						break;
					}
					else if (xRabbit == xPurpose and yRabbit == yPurpose)// проверка на достижение границ поля
					{
						system("cls");
						cout << "you won))";
						temp1 = true;
						break;
					}
					else {
						objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze2);
						objects.moveFox(xRabbit, yRabbit, xFox1, yFox1, Maze2);
						objects.moveFox(xRabbit, yRabbit, xFox2, yFox2, Maze2);
					}
				}
			}
		}
		if (temp1)
		{
			system("cls");
			SetConsoleOutputCP(866);
			ramka(h, width3, height3, Maze3, 11);
			int xRabbit = 5, yRabbit = 10;
			int xFox = 1, yFox = 1;
			int xFox1 = 1, yFox1 = 18;
			int xFox2 = 48, yFox2 = 1;
			int xFox3 = 48, yFox3 = 18;
			int xFox4 = 23, yFox4 = 8;
			int xPurpose = 45, yPurpose = 13;

			char purpose = 'x';


			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;

			SetConsoleOutputCP(65001);
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D"; // отображаем символ зайца

			c.X = xPurpose; // связываем объект координат с позициями "яблока"
			c.Y = yPurpose;

			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию цели
			SetConsoleTextAttribute(h, 4); // устанавливаем красный цвет для отрисовки цели
			putchar(purpose); // отображаем символ цели

			Objects objects = Objects(xRabbit, yRabbit, xFox, yFox, yFox1, xFox1, yFox2, xFox2, yFox3, xFox3, yFox4, xFox4, 40, 15);

			bool temp1 = false;
			bool flag = true; // переменная для управления ходом цикла


			while (flag)
			{
				if (_kbhit())
				{
					Sleep(10); // задержка потока программы на заданный ранее интервал
					int k = _getch(); // считываем код клавиши из буфера
					if (k == 0 || k == 224) // если первый код - вспомогательный, считываем второй код
						k = _getch();
					switch (k) // пропускаем код нажатой клавиши внутрь оператора выбора
					{
					case 80: // если была нажата клавиша вниз
						objects.runDown(xRabbit, yRabbit, Maze3);
						break;
					case 72: // если вверх
						objects.runUp(xRabbit, yRabbit, Maze3);
						break;
					case 75: // если влево
						objects.runLeft(xRabbit, yRabbit, Maze3);
						break;
					case 77: // если вправо
						objects.runRight(xRabbit, yRabbit, Maze3);
						break;
					case 27: // если была нажата клавиша ESC
						flag = false; // устанавливаем флажок на ЛОЖЬ, чтоб закончить показ движения
						break;
					}
					objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze3);
					objects.moveFox(xRabbit, yRabbit, xFox1, yFox1, Maze3);
					objects.moveFox(xRabbit, yRabbit, xFox2, yFox2, Maze3);
					objects.moveFox(xRabbit, yRabbit, xFox3, yFox3, Maze3);
					objects.moveFox(xRabbit, yRabbit, xFox4, yFox4, Maze3);
				}

				if (xRabbit == 0 || xRabbit == width3 - 1 || yRabbit == 0 || yRabbit == height3 - 1) // проверка на достижение границ поля
				{
					flag = false; // пока что - просто установка управляющей переменной цикла
				}
				else {
					Sleep(100);
					if ((xRabbit == xFox and yRabbit == yFox) or (xRabbit == xFox1 and yRabbit == yFox1) or (xRabbit == xFox2 and yRabbit == yFox2)
						or (xRabbit == xFox3 and yRabbit == yFox3) or (xRabbit == xFox4 and yRabbit == yFox4))// проверка на достижение границ поля
					{
						system("cls");
						cout << "you lose((";
						break;
					}
					else if (xRabbit == xPurpose and yRabbit == yPurpose)// проверка на достижение границ поля
					{
						system("cls");
						cout << "you won))";
						temp1 = true;
						break;
					}
					else {
						objects.moveFox(xRabbit, yRabbit, xFox, yFox, Maze3);
						objects.moveFox(xRabbit, yRabbit, xFox1, yFox1, Maze3);
						objects.moveFox(xRabbit, yRabbit, xFox2, yFox2, Maze3);
						objects.moveFox(xRabbit, yRabbit, xFox3, yFox3, Maze3);
						objects.moveFox(xRabbit, yRabbit, xFox4, yFox4, Maze3);
					}
				}
			}
		}
	}
	else {};
	
}

