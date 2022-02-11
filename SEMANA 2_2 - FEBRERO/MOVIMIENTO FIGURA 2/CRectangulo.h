#pragma once

#include"CFigura.h"

class CRectangulo : public CFigura {

public:
	CRectangulo(int x, int y)
		:CFigura(x, y) {
	}
	~CRectangulo() {
	}
	void pintar(Graphics^ g) {

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawRectangle(pen, x, y, width, height);
	}
};