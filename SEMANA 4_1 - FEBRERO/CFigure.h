#pragma once
#ifndef CFIGURE_H
#define CFIGURE_H

using namespace System::Drawing;
using namespace System;

class CFigure {

protected:
	int x, y;
	int dx, dy;
	int width, height;

	int idx, idy;

	float zoom;

	Rectangle porcion;

public:
	CFigure(int x, int y) {
		this->x = x;
		this->y = y;
		dx = dy = 0;
		width = height = 0;
		idx = idy = 0;
		zoom = 1.0f;
	}
	~CFigure() {
	}

	virtual void move(Graphics^) {
		x += dx;
		y += dy;
	}
	virtual void draw(Graphics^, Bitmap^) = 0;

	Rectangle area() {
		return Rectangle(x, y, width * zoom, height * zoom);
	}
    /*Métodos de acceso.*/
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_idy() {
		return idy;
	}
	int get_idx() {
		return idx;
	}
	void set_x(int value) {
		x = value;
	}
	void set_y(int value) {
		y = value;
	}
	void set_idx(int value) {
		idx = value;
	}
	void set_idy(int value) {
		idy = value;
	}
	void set_dx(int value) {
		dx = value;
	}
	void set_dy(int value) {
		dy = value;
	}
};


#endif // !CFIGURE_H
