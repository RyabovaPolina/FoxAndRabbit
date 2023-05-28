#pragma once
#include <time.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Maze.h"

class Objects
{
	int xFox = 1;
	int yFox = 1;
	int xFox1 = 48;
	int yFox1 = 3;
	int xFox2 = 48;
	int yFox2 = 1;
	int xFox3 = 48;
	int yFox3 = 18;
	int xFox4 = 23;
	int yFox4 = 8;
	int xPurpose = 48;
	int yPurpose = 1;
	int xRabbit = 4;
	int yRabbit = 4;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // создание хендла потока вывода
	COORD c; // объект для хранения координат
	CONSOLE_CURSOR_INFO cci = { sizeof(1), false }; // создание параметров на отображение курсора


public:
	Objects(int xRabbit, int yRabbit, int xFox, int yFox, int xFox1, int yFox1, int xFox2, int yFox2, int xFox3, int yFox3, int xFox4, int yFox4, int xPurpose, int yPurpose)
	{
		this->xFox = xFox;
		this->yFox = yFox;
		this->xFox1 = xFox1;
		this->yFox1 = yFox1;
		this->xFox2 = xFox2;
		this->yFox2 = yFox2;
		this->xFox3 = xFox3;
		this->yFox3 = yFox3;
		this->xFox4 = xFox4;
		this->yFox4 = yFox4;
		this->xPurpose = xPurpose;
		this->yPurpose = yPurpose;
		this->xRabbit = xRabbit;
		this->yRabbit = yRabbit;
	}

	void moveFox(int &xRabbit, int &yRabbit, int &xFox, int &yFox, string Maze[])
	{
		if (xFox + 1 < 50 and xFox + 1 > 0 and xFox > 0 and xFox < 50 and xFox < xRabbit and Maze[yFox][xFox + 1] == ' ')
		{
			c.X = xFox;
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xFox += 1;

			c.X = xFox; // связываем объект координат с позициями "яблока"
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 12); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u054B"; // отображаем символ зайца
		}
		else if (xFox - 1 < 50 and xFox - 1 > 0 and xFox > 0 and xFox < 50 and xFox > xRabbit and Maze[yFox][xFox - 1] == ' ')
		{
			c.X = xFox;
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xFox -= 1;

			c.X = xFox; // связываем объект координат с позициями "яблока"
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 12); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u054B"; // отображаем символ зайца
		}
		else if (yFox + 1 < 20 and yFox + 1 > 0 and yFox < 20 and yFox > 0 and yFox < yRabbit and Maze[yFox + 1][xFox] == ' ')
		{
			c.X = xFox;
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			yFox += 1;

			c.X = xFox; // связываем объект координат с позициями "яблока"
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 12); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u054B"; // отображаем символ зайца
		}
		else if (yFox - 1 < 20 and yFox - 1 > 0 and yFox < 20 and yFox > 0 and yFox > yRabbit and Maze[yFox - 1][xFox] == ' ')
		{
			c.X = xFox; // связываем объект координат с позициями "яблока"
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			yFox -= 1;

			c.X = xFox; // связываем объект координат с позициями "яблока"
			c.Y = yFox;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 12); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u054B"; // отображаем символ зайца
		}
		else {}
		/*else if ((xFox == xRabbit and yFox == yRabbit))
		{
			system("cls");
			cout << "you lose((";
		}*/
	}
	void runDown(int& xRabbit, int& yRabbit, string Maze[])
	{
		int dx = 0, dy = 0;
		bool flag = true;
		dy = 1; // то приращение по оси ординат будет положительным
		dx = 0;
		if (Maze[yRabbit + dy][xRabbit + dx] == ' ')
		{
			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xRabbit += dx; // связываем объект координат с позициями "яблока"
			yRabbit += dy;

			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D";  // отображаем символ зайца
		}
		else {};
	}
	void runUp(int& xRabbit, int& yRabbit, string Maze[])
	{
		int dx = 0, dy = 0;
		bool flag = true;
		dy = -1; // то приращение по оси ординат будет положительным
		dx = 0;
		if (Maze[yRabbit + dy][xRabbit + dx] == ' ')
		{
			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xRabbit += dx; // связываем объект координат с позициями "яблока"
			yRabbit += dy;

			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D";  // отображаем символ зайца
		}
		else {};
	}
	void runLeft(int& xRabbit, int& yRabbit, string Maze[])
	{
		int dx = 0, dy = 0;
		bool flag = true;
		dy = 0; // то приращение по оси ординат будет положительным
		dx = -1;
		if (Maze[yRabbit + dy][xRabbit + dx] == ' ')
		{
			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xRabbit += dx; // связываем объект координат с позициями "яблока"
			yRabbit += dy;

			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D"; // отображаем символ зайца
		}
		else {};
	}
	void runRight(int& xRabbit, int& yRabbit, string Maze[])
	{
		int dx = 0, dy = 0;
		bool flag = true;
		dy = 0; // то приращение по оси ординат будет положительным
		dx = 1;
		if (Maze[yRabbit + dy][xRabbit + dx] == ' ')
		{
			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // двигаем туда курсор
			putchar(' '); // и отображаем пробел (затирка хвоста)
			xRabbit += dx; // связываем объект координат с позициями "яблока"
			yRabbit += dy;

			c.X = xRabbit; // связываем объект координат с позициями "яблока"
			c.Y = yRabbit;
			SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зайца
			SetConsoleTextAttribute(h, 15); // устанавливаем красный цвет для отрисовки зайца
			cout << u8"\u020D"; // отображаем символ зайца
		}
		else {};
	}
	
};