#pragma once
#ifndef CCONTROLADORA_H
#define CCONTROLADORA_H

#include"CPelota.h"

class CControladora {

private:
	CPelota* pelota;

	void draw() {
		pelota->draw();
	}
public:
	CControladora() {
		pelota = new CPelota(10, 10);
	}
	~CControladora() {
		delete pelota;
	}
	void erase() {
		pelota->erase();
	}
	void move(int widthS, int heightS) {
		pelota->move(widthS, heightS);

		/*Draw.*/
		draw();
	}
};

#endif