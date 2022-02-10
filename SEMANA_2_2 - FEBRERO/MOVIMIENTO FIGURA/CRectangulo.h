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

		SolidBrush^ sB = gcnew SolidBrush(Color::FromArgb(_r, _g, _b));
		g->FillRectangle(sB, x, y, width, height);
	}
};