#pragma once

#include"CFigura.h"

class CRombo : public CFigura {

public:
	CRombo(int x, int y)
		:CFigura(x, y) {
	}
	~CRombo() {
	}
	void pintar(Graphics^ g) {

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawLine(pen, x + (width / 2), y, x + width, y + (height / 2));
		g->DrawLine(pen, x + width, y + (height / 2), x + (width / 2), y + height);
		g->DrawLine(pen, x + (width / 2), y + height, x, y + (height / 2));
		g->DrawLine(pen, x, y + (height / 2), x + (width / 2), y);
	}
};