#pragma once
#ifndef CPIEDRA_H
#define CPIEDRA_H

#include"CSprite.h"

class CPiedra : public CSprite {

public:
	CPiedra(int x, int y)
		:CSprite(x, y) {
		width = 214;
		height = 263;

		zoom = 0.3f;
	}
	~CPiedra() {
	}
	void draw(Graphics^ gr, Bitmap^ btpPiedra) {

		Rectangle porcion = Rectangle(0 * width, 0 * height, width, height);

		gr->DrawImage(btpPiedra, area(), porcion, GraphicsUnit::Pixel);
		gr->DrawRectangle(gcnew Pen(Color::Black), area());
	}
};

#endif