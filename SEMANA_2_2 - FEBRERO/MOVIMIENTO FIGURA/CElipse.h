#pragma once

#include"CFigura.h"

class CElipse : public CFigura {

public:
	CElipse(int x, int y)
		:CFigura(x, y) {
	}
	~CElipse() {
	}
	void pintar(Graphics^ g) {

		SolidBrush^ sB = gcnew SolidBrush(Color::FromArgb(_r, _g, _b));
		g->FillEllipse(sB, x, y, width, height);
	}
};