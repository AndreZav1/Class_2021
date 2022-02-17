#pragma once
#ifndef CSPRITE_H
#define CSPRITE_H

using namespace System::Drawing;

class CSprite {

protected:
	int x, y;
	int dx, dy;
	int width, height;

	/*zoom*/
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

	void set_dy(int value) {
		dy = value;
	}
	void set_dx(int value) {
		dx = value;
	}
};


#endif