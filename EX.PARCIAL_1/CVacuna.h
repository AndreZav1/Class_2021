#pragma once

#include"CPersonaje.h"

class CVacuna : public CPersonaje {

public:
	CVacuna(int x, int y, int color)
		:CPersonaje(x, y, color) {
		dx = 1;
		dy = 0;
		width = 4;
		height = 1;
	}
	~CVacuna() {
	}
	void Borrar() {

		Console::SetCursorPosition(x, y);
		cout << "   ";
	}
	void Mover(int widthS, int heightS) {

		/*Validamos el movimiento*/
		if (x + dx > 0 && x + dx + width < widthS) {
			x += dx;
		}
		if (y + dy > 0 && y + dy + height < heightS) {
			y += dy;
		}
		/*Validación de que cuando choque a algún lateral de
				mi consola, mi vacuna rebote.*/
		if (x + dx < 5 || x + dx + width > widthS - 5) {
			dx *= -1;
		}
		if (y + dy < 5 || y + dy + height > heightS) {
			dy *= -1;
		}
	}
	void Pintar() {

		Console::ForegroundColor = (ConsoleColor)color;

		Console::SetCursorPosition(x, y);
		cout << "|->";

		Console::ForegroundColor = ConsoleColor::White;
	}
};