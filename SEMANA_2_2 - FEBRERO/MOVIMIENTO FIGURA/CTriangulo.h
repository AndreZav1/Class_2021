#pragma once

#include"CFigura.h"	

class CTriangulo :public CFigura {

public:
	CTriangulo(int x, int y)
		:CFigura(x, y) {
	}
	~CTriangulo() {
	}
	void pintar(Graphics^ g) {

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawLine(pen, x, y, x + width, y + height);
		g->DrawLine(pen, x + width, y + height, x, y + height);
		g->DrawLine(pen, x, y + height, x, y);
	}
};