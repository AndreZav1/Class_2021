#pragma once
#ifndef CFANTASMA_H
#define CFANTASMA_H

#include"CSprite.h"
#include<string>

using std::string;
using System::Random;

string Tipo_Fantasma[] = { "ROJO", "NARANJA","ROSADO", "CELESTE", "MORADO" };

class CFantasma : public CSprite {

private:
	string type;

public:
	CFantasma(int x, int y, int indice, int speed)
		:CSprite(x, y) {
		this->type = Tipo_Fantasma[indice];
		if (type == "ROJO") {
			idx = 0;
			idy = 0;
		}
		if (type == "NARANJA") {
			idx = 2;
			idy = 0;
		}
		if (type == "ROSADO") {
			idx = 4;
			idy = 0;
		}
		if (type == "CELESTE") {
			idx = 6;
			idy = 0;
		}
		if (type == "MORADO") {
			idx = 8;
			idy = 0;
		}
		Random r;
		dx = dy = speed;
		width = 31.5f;
		height = 32.0f;
	}
	~CFantasma() {
	}
	void move(Graphics^ gr) {
		if (x + dx < 0 || x + (width * zoom) + dx >gr->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy < 0 || y + (height * zoom) + dy >gr->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
	void draw(Graphics^ gr, Bitmap^ btp) {
		porcion = Rectangle(idx * width, idy * height, width, height);
		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);
		idx += 1;
		if (idx >= 0 && idx <= 1) {
			if (idx == 1)idx = 0;
		}
		else
		{
			if (idx >= 2 && idx <= 3) {
				if (idx == 3)idx = 2;
			}
			else
			{
				if (idx >= 4 && idx <= 5) {
					if (idx == 5)idx = 4;
				}
				else
				{
					if (idx >= 6 && idx <= 7) {
						if (idx == 7)idx = 6;
					}
					else
					{
						if (idx >= 8 && idx <= 9) {
							if (idx == 9)idx = 8;
						}
					}
				}
			}
		}
	}
};

#endif