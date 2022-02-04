#pragma once

#include"CPersonaje.h"

class CVirus : public CPersonaje {

public:
	CVirus(int x, int y, int color)
		:CPersonaje(x, y, color) {
		width = 10;
		height = 5;
	}
	void Borrar() {

		Console::SetCursorPosition(x, y);
		cout << "     ";
		Console::SetCursorPosition(x, y + 1);
		cout << "        ";
		Console::SetCursorPosition(x, y + 2);
		cout << "         ";
		Console::SetCursorPosition(x, y + 3);
		cout << "        ";
		Console::SetCursorPosition(x, y + 4);
		cout << "     ";
	}
	void Pintar() {

		Console::ForegroundColor = (ConsoleColor)color;

		Console::SetCursorPosition(x, y);
		cout << "    q";
		Console::SetCursorPosition(x, y + 1);
		cout << " o.-o-.o";
		Console::SetCursorPosition(x, y + 2);
		cout << "o-(ooo)-o";
		Console::SetCursorPosition(x, y + 3);
		cout << " o.-o-.o";
		Console::SetCursorPosition(x, y + 4);
		cout << "    q";

		Console::ForegroundColor = ConsoleColor::White;
	}
	virtual void Mover(int, int) = 0;
};