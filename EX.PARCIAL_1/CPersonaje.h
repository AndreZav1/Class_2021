#pragma once

#include<iostream>

using namespace std;
using namespace System::Drawing;
using namespace System;

class CPersonaje {

protected:
	int x, y;
	int dx, dy;
	int width, height;
	int color;

public:
	CPersonaje(int x, int y, int color) {
		this->x = x;
		this->y = y;

		this->color = color;
	}
	~CPersonaje() {
	}
	//Método abstracto: Obligo a implementar estos métodos en las clases hijas.
	virtual void Borrar() = 0;
	virtual void Mover(int, int) = 0;
	virtual void Pintar() = 0;

	Rectangle area() {
		return Rectangle(x, y, width, height);
	}

	void set_dx(int value) {
		dx = value;
	}
	void set_dy(int value) {
		dy = value;
	}
	int get_color() {
		return color;
	}
	void set_color(int value) {
		color = value;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
};
