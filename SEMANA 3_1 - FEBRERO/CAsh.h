#pragma once
#ifndef CASH_H
#define CASH_H

using namespace System::Drawing;

class CAsh {

private:
	/*Para su posición*/
	int x, y;
	/*Diferenciales de velocidad*/
	int dx, dy;
	/*Dimensiones de figura.*/
	int width, height;

	/*id*/
	int idx, idy;
	/*zoom*/
	float zoom;

	/*Vidas*/
	int health_points;
public:
	CAsh(int x, int y) {
		this->x = x;
		this->y = y;

		dx = dy = 0;

		width = 68;
		height = 72;

		idx = idy = 0;

		zoom = 1.0f;

		health_points = 5;
	}
	~CAsh() {
	}
	void mover(Graphics^ gr) {
		
		if (x + dx > 0 && x + (width * zoom) + dx < gr->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy > 0 && y + (height * zoom) + dy < gr->VisibleClipBounds.Height) {
			y += dy;
		}
	}
	void pintar(Graphics^ gr, Bitmap^ bitAsh) {
		/*Obtener la porción de mi imagen a imprimir.*/
		Rectangle porcion = Rectangle(idx * width, idy * height, width, height);

		gr->DrawImage(bitAsh, area(), porcion, GraphicsUnit::Pixel);

		if (dx != 0 || dy != 0) {
			idx += 1;
		}
		if (idx == 3)idx = 0;
	}
	Rectangle area() {
		return Rectangle(x, y, width * zoom, height * zoom);
	}

	void set_dx(int value) {
		dx = value;
	}
	void set_dy(int value) {
		dy = value;
	}
	void set_idy(int value) {
		idy = value;
	}

	void decrease_hp() {
		health_points -= 1;
	}
	int get_hp() {
		return health_points;
	}
};

#endif