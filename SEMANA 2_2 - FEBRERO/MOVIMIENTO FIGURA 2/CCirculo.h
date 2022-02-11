#pragma once

#include"CFigura.h"

class CCirculo : public CFigura {

public:
	CCirculo(int x, int y)
		:CFigura(x, y) {
	}
	~CCirculo() {
	}
	void pintar(Graphics^ g) {

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawEllipse(pen, x, y, width, width);
	}
};
