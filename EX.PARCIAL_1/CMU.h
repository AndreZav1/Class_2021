#pragma once

#include"CVirus.h"

class CMU : public CVirus {

public:
	CMU(int x, int y, int color)
		:CVirus(x, y, color) {

		dy = 0;
		dx = 2;
	}
	~CMU() {
	}
	void Mover(int widthS, int heightS) {

		if (x + dx < 0 || x + dx + width > widthS) {
			dx *= -1;
		}
		x += dx;
	}
};