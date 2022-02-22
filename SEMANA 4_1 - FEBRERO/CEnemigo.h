#pragma once
#ifndef CENEMIGO_H
#define CENEMIGO_H

#include"CFigure.h"
#include"CChrono.h"

class CEnemigo : public CFigure {

private:
	int type;

public:
	CEnemigo(int x, int y, int type)
		:CFigure(x, y) {
		width = 52;
		height = 76;
		dx = dy = 2;
		this->type = type;
	}
	CEnemigo(int x, int y, int dx, int dy, int idx, int idy, int type)
		:CFigure(x, y) {
		width = 52;
		height = 76;
		this->dx = dx;
		this->dy = dy;
		this->idx = idx;
		this->idy = idy;
		this->type = type;
	}
	~CEnemigo() {
	}
	void move(Graphics^ gr, CChrono* chrono) {

		if (type == 1) {
			int speed = 1;

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
				if (this->x < chrono->get_y()) {
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
		else
		{
			if (type == 2) {
				if (x + dx < 0 || x + width > gr->VisibleClipBounds.Width) {
					dx *= -1;
				}
				if (dx > 0)idy = 2;
				if (dx < 0)idy = 1;
				x += dx;
			}
			else
			{
				if (type == 3) {
					if (y + dy < 0 || y + (height * zoom) + dy > gr->VisibleClipBounds.Height) {
						dy *= -1;
					}
					if (dy > 0)idy = 0;
					if (dy < 0)idy = 3;
					y += dy;
				}
			}
		}
	}
	void draw(Graphics^ gr, Bitmap^ btp) {

		porcion = Rectangle(idx * width, idy * height, width, height);
		
		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);
		
		idx += 1;
		if (idx == 3)idx = 0;
	}
	int get_type() {
		return type;
	}
	void set_type(int value) {
		type = value;
	}
};

#endif