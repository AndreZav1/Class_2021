#pragma once
#ifndef CENEMIGO_H
#define CENEMIGO_H

#include"CFigure.h"
#include"CChrono.h"

class CEnemigo : public CFigure {

public:
	CEnemigo(int x, int y)
		:CFigure(x, y) {
		width = 52;
		height = 76;
		
		zoom = 1.0f;
	}
	~CEnemigo() {
	}
	void move(Graphics^, CChrono* chrono) {

		int speed = 5;

		if (this->x > chrono->get_x()) {
			this->set_dx(-speed);
			this->set_dy(0);
		}
		else {
			if (this->x < chrono->get_x()) {
				this->set_dx(speed);
				this->set_dy(0);
			}
		}

		if (this->y > chrono->get_y()) {
			this->set_dy(-speed);
			this->set_dx(0);
		}
		else {
			if (this->y < chrono->get_y()) {
				this->set_dy(speed);
				this->set_dx(0);
			}
		}

		if (dx > 0)idy = 2;
		if (dx < 0)idy = 1;
		if (dy > 0)idy = 0;
		if (dy < 0)idy = 3;

		x += dx;
		y += dy;
	}
	void draw(Graphics^ gr, Bitmap^ btp) {

		porcion = Rectangle(idx * width, idy * height, width, height);

		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);

		idx += 1;
		if (idx == 3)idx = 0;
	}
};

#endif