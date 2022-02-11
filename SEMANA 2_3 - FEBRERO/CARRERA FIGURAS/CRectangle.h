#pragma once
#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include"CFigura.h"

class CRectangle : public CFigura {

public:
	CRectangle(int x, int y)
		:CFigura(x, y) {

		width = 40;
		height = 70;
	}
	~CRectangle() {
	}
	void pintar(Graphics^ gr) {

		SolidBrush^ sb = gcnew SolidBrush(Color::Aqua);
		gr->FillRectangle(sb, x, y, width, height);
	}
};

#endif // !CRECTANGLE_H
