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

		SolidBrush^ sB = gcnew SolidBrush(Color::FromArgb(_r, _g, _b));
		g->FillEllipse(sB, x, y, width, width);
	}
};