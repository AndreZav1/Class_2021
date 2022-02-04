#pragma once

#include"CPersonaje.h"

class CMonigote : public CPersonaje {

public:
	CMonigote(int x, int y, int color)
		:CPersonaje(x, y, color) {
		Random r;
		dx = dy = r.Next(2, 5);
		width = 2;
		height = 2;
	}
	~CMonigote() {
	}
	void Borrar() {

		Console::SetCursorPosition(x, y);
		cout << " ";
		Console::SetCursorPosition(x, y + 1);
		cout << " ";
	}
	void Mover(int widthS, int heightS) {

		if (x + dx < 0 || x + width + dx > widthS) {
			dx *= -1;
		}
		if (y + dy < 0 || y + height + dy > heightS) {
			dy *= -1;
		}

		x += dx;
		y += dy;
	}
	void Pintar() {

		Console::ForegroundColor = (ConsoleColor)color;
		Console::SetCursorPosition(x, y);
		cout << "O";
		Console::SetCursorPosition(x, y + 1);
		cout << "+";
		Console::ForegroundColor = ConsoleColor::White;
	}
};
