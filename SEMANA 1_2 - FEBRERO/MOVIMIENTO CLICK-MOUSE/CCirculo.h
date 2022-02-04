#pragma once

#include"CFigura.h"

class CCirculo : public CFigura {

public:
	CCirculo(int x, int y)
		:CFigura(x, y) {
	}
	~CCirculo() {
	}
	void Pintar(Graphics^ g) {

		Pen^ p = gcnew Pen(Brushes::Brown, 4);
		g->DrawEllipse(p, x, y, width, height);
	}
};
