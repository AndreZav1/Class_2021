#pragma once
#ifndef CFIGURA_H
#define CFIGURA_H

#include<stdlib.h>
#include<ctime>

using namespace std;
using namespace System::Drawing;

class CFigura {

protected:
	int x, y;
	int dx, dy;
	int width, height;

	bool llego;
	int place;
	int victorias;
public:
	CFigura(int x, int y) {
		this->x = x;
		this->y = y;
		llego = false;
		place = 0;
		victorias = 0;
	}
	~CFigura() {
	}
	virtual void mover(Graphics^ g) {

		if (x + width >= 700) {
			llego = true;
		}
		if (!llego) {
			x += rand() % 10 + 5;
		}
	}

	virtual void pintar(Graphics^) = 0;

	int get_victorias() {
		return victorias;
	}
	int get_place() {
		return place;
	}
	bool get_llego() {
		return llego;
	}
	void set_x(int value) {
		x = value;
	}
	void set_llego(bool value) {
		llego = value;
	}
	void set_place(int value) {
		place = value;
	}
	void incrementar_victoria() {
		victorias += 1;
	}
};

#endif