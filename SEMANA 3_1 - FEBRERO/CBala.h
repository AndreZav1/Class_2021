#pragma once

using namespace System::Drawing;
using namespace System;

class CBala {

private:
	int x, y;
	int dy;
	int width, height;

	float zoom;

	bool visible;
public:
	CBala(Graphics^ gr, int x, int y) {
		Random r;
		width = 32;
		height = 32;
		this->x = x;
		this->y = y;
		dy = r.Next(2, 7);
		zoom = 1.2f;

		visible = true;
	}
	~CBala() {
	}
	void mover(Graphics^ gr) {

		if (y + dy + (height * zoom) > gr->VisibleClipBounds.Height) {
			dy = 0;
		}
		y += dy;
	}
	void pintar(Graphics^ gr, Bitmap^ btpBala) {

		Rectangle porcion = Rectangle(0 * width, 0 * height, width, height);
		gr->DrawImage(btpBala, area(), porcion, GraphicsUnit::Pixel);
	}
	Rectangle area() {
		return Rectangle(x, y, width * zoom, height * zoom);
	}
	bool get_visible() {
		return visible;
	}
	void set_visible(bool value) {
		visible = value;
	}
	int get_dy() {
		return dy;
	}
};