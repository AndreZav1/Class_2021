#pragma once
#ifndef CSPRITE_H
#define CSPRITE_H

using namespace System::Drawing;
using namespace System;

class CSprite {

protected:
	/*Posiciones.*/
	int x, y;
	/*Dif.velocidad.*/
	int dx, dy;
	/*Dimensiones.*/
	int width, height;

	/*Zoom.*/
	float zoom;

public:
	CSprite(int x, int y) {
		this->x = x;
		this->y = y;
		dx = dy = 0;
		width = height = 0;

		zoom = 1.0f;
	}
	~CSprite() {
	}
	virtual void move(Graphics^) {
		x += dx;
		y += dy;
	}

	virtual void draw(Graphics^, Bitmap^) = 0;

	Rectangle area() {
		return Rectangle(x, y, width * zoom, height * zoom);
	}

	/*Métodos acceso*/
	void set_dx(int value) {
		dx = value;
	}
	void set_dy(int value) {
		dy = value;
	}
};


#endif