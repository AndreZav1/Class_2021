#pragma once
#ifndef CBONUS_H
#define CBONUS_H

#include"CSprite.h"

class CBonus : public CSprite {

public:
	CBonus(int x, int y, int idx)
		:CSprite(x, y) {
		width = 145.2f;
		height = 123.0f;

		this->idx = idx;

		zoom = 0.3f;
	}
	~CBonus() {
	}
	void draw(Graphics^ gr, Bitmap^ btp) {
		porcion = Rectangle(idx * width, idy * height, width, height);
		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);
	}
	void set_idx(int value) {
		idx = value;
	}
};

#endif