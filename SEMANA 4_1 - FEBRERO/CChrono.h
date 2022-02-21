#pragma once
#ifndef CCHRONO_H
#define CCHRONO_H

#include"CFigure.h"

class CChrono : public CFigure {

public:
	CChrono(int x, int y)
		:CFigure(x, y) {
		width = 48;
		height = 72;
	}
	~CChrono() {
	}
	void move(Graphics^ gr) {

		if (x + dx > 0 && x + (width * zoom) + dx < gr->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy > 0 && y + (height * zoom) + dy < gr->VisibleClipBounds.Height) {
			y += dy;
		}

		if (dx > 0)idy = 2;
		if (dx < 0)idy = 1;
		if (dy > 0)idy = 0;
		if (dy < 0)idy = 3;

		/*if (dx == 0 && dy == 0) {
			idy = 0;
			idx = 0;
		}*/
	}
	void draw(Graphics^ gr, Bitmap^ btp) {

		porcion = Rectangle(idx * width, idy * height, width, height);

		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);

		if (dx != 0 || dy != 0) {
			idx += 1;
		}
		if (idx == 3)idx = 0;
	}

};

#endif