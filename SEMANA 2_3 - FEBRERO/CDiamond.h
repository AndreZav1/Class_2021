#pragma once
#ifndef CDIAMOND_H
#define CDIAMOND_H

#include"CFigura.h"

class CDiamond : public CFigura {

public:
	CDiamond(int x, int y)
		:CFigura(x, y) {

		width = height = 40;
	}
	~CDiamond() {
	}
	void pintar(Graphics^ gr) {

		Pen^ pen = gcnew Pen(Color::Chartreuse, 4);
		gr->DrawLine(pen, x + (width / 2), y, x + width, y + (height / 2));
		gr->DrawLine(pen, x + width, y + (height / 2), x + (width / 2), y + height);
		gr->DrawLine(pen, x + (width / 2), y + height, x, y + (height / 2));
		gr->DrawLine(pen, x, y + (height / 2), x + (width / 2), y);
	}
};

#endif // !CDIAMOND_H
