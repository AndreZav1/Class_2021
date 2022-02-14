#pragma once
#ifndef CBOLAS_H
#define CBOLAS_H

using namespace System::Drawing;
using namespace System;

class CBolas {

private:
	int x, y;
	int dy;
	int width, height;

	bool visible;
public:
	CBolas(int x, int y) {
		Random r;
		this->x = x;
		this->y = y;
		dy = r.Next(2, 7);

		width = height = 25;

		visible = true;
	}
	~CBolas() {
	}
	void mover(Graphics^ gr) {

		if (y + height + dy > gr->VisibleClipBounds.Height) {
			dy = 0;
		}
		y += dy;
	}
	void pintar(Graphics^ gr) {
		SolidBrush^ sB = gcnew SolidBrush(Color::Black);
		gr->FillEllipse(sB, area());
	}
	bool get_visible() {
		return visible;
	}
	void set_visible(bool value) {
		visible = value;
	}
	Rectangle area() {
		return Rectangle(x, y, width, height);
	}
};


#endif