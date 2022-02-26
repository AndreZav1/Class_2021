#pragma once
#ifndef CPACMAN_H
#define CPACMAN_H

#include"CSprite.h"

class CPacman : public CSprite {

private:
	int hp;
	int points;
	int speed;

	/*Guardando coordenada inicial de X e Y.*/
	int save_x, save_y;
public:
	CPacman(int x, int y, int hp)
		:CSprite(x, y) {
		this->hp = hp;
		save_x = x;
		save_y = y;
		points = 0;
		width = 32.5f;
		height = 30.75f;
		speed = 5;
		dx = dy = 0;
	}
	~CPacman() {
	}
	void move(Graphics^ gr) {
		if (x + dx > 0 && x + (width * zoom) + dx < gr->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy > 0 && y + (height * zoom) + dy < gr->VisibleClipBounds.Height) {
			y += dy;
		}
		/*Cambiar la animación dependiendo de la orientación en la que se mueva el pacman.*/
		if (dx > 0)idy = 0;
		if (dx < 0)idy = 2;
		if (dy > 0)idy = 1;
		if (dy < 0)idy = 3;
	}
	void draw(Graphics^ gr, Bitmap^ btp) {
		porcion = Rectangle(idx * width, idy * height, width, height);
		gr->DrawImage(btp, area(), porcion, GraphicsUnit::Pixel);
		idx += 1;
		if (idx == 2)idx = 0;
	}
	void decrease_hp() {
		hp -= 1;
	}
	void regresa_inicio() {
		x = save_x;
		y = save_y;
	}
	int get_hp() {
		return hp;
	}
	int get_points() {
		return points;
	}
	int get_speed() {
		return speed;
	}
	void increase_points(int value) {
		points += value;
	}
	void set_speed(int value) {
		speed = value;
	}
};

#endif