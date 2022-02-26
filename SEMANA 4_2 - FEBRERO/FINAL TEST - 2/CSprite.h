#pragma once
#ifndef CSPRITE_H
#define CSPRITE_H

using namespace System::Drawing;

class CSprite {

protected:
	int x, y;
	int dx, dy;
	int width, height;

	int idx, idy;

	float zoom;

	Rectangle porcion;

	bool visible;
public:
	CSprite(int x, int y) {
		this->x = x;
		this->y = y;
		dx = dy = 0;
		width = height = 0;
		zoom = 1.0f;
		idx = idy = 0;

		visible = true;
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
	Rectangle hit_box() {
		return Rectangle(0, 0, 0, 0);
	}
	/*Métodos de acceso.*/
	bool get_visible() {
		return visible;
	}
	void set_dx(int value) {
		dx = value;
	}
	void set_dy(int value) {
		dy = value;
	}
	void set_visible(bool value) {
		visible = value;
	}
};

#endif