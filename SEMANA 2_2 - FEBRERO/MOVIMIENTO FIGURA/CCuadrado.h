#pragma once

#include"CFigura.h"

class CCuadrado : public CFigura {

public:
	CCuadrado(int x, int y)
		:CFigura(x, y) {
	}
	~CCuadrado() {
	}
	void pintar(Graphics^ g) {

		SolidBrush^ sB = gcnew SolidBrush(Color::FromArgb(_r, _g, _b));
		g->FillRectangle(sB, x, y, width, width);
	}
};