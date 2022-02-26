#pragma once
#ifndef CPACDOT_H
#define CPACDOT_H

#include"CSprite.h"
#include<string>

using std::string;

class CPacdot : public CSprite {

public:
	CPacdot(int x, int y)
		:CSprite(x, y) {
		width = 348;
		height = 150;

		zoom = 0.3f;
	}
	~CPacdot() {
	}
	void draw(Graphics^ gr, Bitmap^ btp) {
		porcion = Rectangle(idx * width, idy * height, width, height);
		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);
		gr->DrawRectangle(gcnew Pen(Color::Black, 2), area());
		gr->DrawRectangle(gcnew Pen(Color::Blue, 2), hit_box());
	}
	Rectangle hit_box() {
		return Rectangle(x + 33, y + 14, (width * zoom) / 3, (height * zoom) / 2);
	}
};

#endif