#pragma once

using namespace System;
using namespace System::Drawing;

class CFigura {

protected:
	int x, y;
	int dx, dy;
	int width, height;

public:
	CFigura(int x, int y) {
		Random r;
		this->x = x;
		this->y = y;
		dx = dy = r.Next(2, 5);

		width = height = 40;
	}
	~CFigura() {
	}
	void Mover(Graphics^ g) {

		if (x + dx < 0 || x + dx + width > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + height > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
	/*Método abstracto.*/
	virtual void Pintar(Graphics^) = 0;
};
