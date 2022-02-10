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

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawEllipse(pen, x, y, width, height);
	}
};
