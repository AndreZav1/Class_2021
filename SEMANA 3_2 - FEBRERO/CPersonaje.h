#pragma once
#ifndef CPERSONAJE_H
#define CPERSONAJE_H

#include"CSprite.h"

class CPersonaje : public CSprite {

private:
	int idx, idy;

public:
	CPersonaje(int x, int y, int idy, int idx)
		:CSprite(x, y) {

		this->idy = idy;
		this->idx = idx;

		width = 31.83f;
		height = 32.0f;
		
		zoom = 1.8f;
	}
	~CPersonaje() {
	}
	void move(Graphics^ gr) {

		if (x + dx > 0 && x + (width * zoom) + dx < gr->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy > 0 && y + (height * zoom) + dy < gr->VisibleClipBounds.Height) {
			y += dy;
		}

		if (idy >= 0 && idy <= 3) {
			if (dx > 0)idy = 2;
			if (dx < 0)idy = 1;
			if (dy > 0)idy = 0;
			if (dy < 0)idy = 3;
		}
		if (idy >= 4 && idy <= 7) {
			if (dx > 0)idy = 6;
			if (dx < 0)idy = 5;
			if (dy > 0)idy = 4;
			if (dy < 0)idy = 7;
		}
	}
	void draw(Graphics^ gr, Bitmap^ btpPerso) {

		Rectangle porcion = Rectangle(idx * width, idy * height, width, height);

		gr->DrawImage(btpPerso, area(), porcion, GraphicsUnit::Pixel);
		gr->DrawRectangle(gcnew Pen(Color::Blue, 3), area());
		gr->DrawRectangle(gcnew Pen(Color::Red, 3), next_area());

		if (dx != 0 || dy != 0) {
			idx += 1;
		}

		if (idy >= 0 && idy <= 3) {
			if (idx >= 0 && idx <= 2) {
				if (idx == 2) {
					idx = 0;
				}
			}
			if (idx >= 3 && idx <= 5) {
				if (idx == 5) {
					idx = 3;
				}
			}
			if (idx >= 6 && idx <= 8) {
				if (idx == 8) {
					idx = 6;
				}
			}
			if (idx >= 9 && idx <= 11) {
				if (idx == 11) {
					idx = 9;
				}
			}
		}
		if (idy >= 4 && idy <= 7) {
			if (idx >= 0 && idx <= 2) {
				if (idx == 2) {
					idx = 0;
				}
			}
			if (idx >= 3 && idx <= 5) {
				if (idx == 5) {
					idx = 3;
				}
			}
			if (idx >= 6 && idx <= 8) {
				if (idx == 8) {
					idx = 6;
				}
			}
			if (idx >= 9 && idx <= 11) {
				if (idx == 11) {
					idx = 9;
				}
			}
		}
	}

	Rectangle next_area() {
		return Rectangle(x + dx, y + dy, width * zoom, height * zoom);
	}
};

#endif