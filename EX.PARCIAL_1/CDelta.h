#pragma once

#include"CVirus.h"

class CDelta : public CVirus {

public:
	CDelta(int x, int y, int color)
		:CVirus(x, y, color) {

		dy = 2;
		dx = 0;
	}
	~CDelta() {
	}
	void Mover(int widthS, int heightS) {

		if (y + dy < 0 || y + dy + height > heightS) {
			dy *= -1;
		}
		y += dy;
	}
};