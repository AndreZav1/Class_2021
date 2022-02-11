#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include"CFigura.h"

class CCircle : public CFigura {

public:
	CCircle(int x, int y)
		:CFigura(x, y) {

		width = height = 40;
	}
	~CCircle() {
	}
	void pintar(Graphics^ gr) {

		SolidBrush^ sb = gcnew SolidBrush(Color::BlueViolet);
		gr->FillEllipse(sb, x, y, width, height);
	}
};

#endif // !CCIRCLE_H
