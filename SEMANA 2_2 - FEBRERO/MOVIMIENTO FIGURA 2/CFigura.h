#pragma once

using System::Random;
using System::Drawing::Graphics;
using System::Drawing::Pen;
using System::Drawing::Color;

class CFigura {

protected:
	int x, y;
	int dx, dy;
	int width, height;

	/*Variables rgb.*/
	int _r, _g, _b;
public:
	CFigura(int x, int y) {
		Random r;
		this->x = x;
		this->y = y;
		dx = dy = r.Next(2, 7);
		width = r.Next(20, 61);
		height = r.Next(20, 61);

		_r = r.Next(50, 220);
		_g = r.Next(50, 220);
		_b = r.Next(50, 220);
	}
	~CFigura() {
	}
	void mover(Graphics^ g) {

		if (x + dx < 0 || x + width + dx > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy < 0 || y + height + dy > g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
	virtual void pintar(Graphics^) = 0;
};