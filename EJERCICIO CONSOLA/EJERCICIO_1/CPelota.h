#pragma once
#ifndef CPELOTA_H
#define CPELOTA_H

#include<iostream>

using System::Console;

class CPelota {

private:
	int x, y;
	int dx, dy;
	int width, height;

public:
	CPelota(int x, int y) {
		srand(time(NULL));
		this->x = x;
		this->y = y;
		dx = dy = 1 + rand() % 4;
		width = 1;
		height = 1;
	}
	~CPelota() {
	}
	void erase() {

		Console::SetCursorPosition(x, y);
		std::cout << " ";
	}
	void move(int widthS, int heightS) {

		if (x + dx < 0 || x + width + dx > widthS) {
			dx *= -1;
		}
		if (y + dy < 0 || y + height + dy > heightS) {
			dy *= -1;
		}

		x += dx;
		y += dy;
	}
	void draw() {

		Console::SetCursorPosition(x, y);
		std::cout << "*";
	}
};

#endif