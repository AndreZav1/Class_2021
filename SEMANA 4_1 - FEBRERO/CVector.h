#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

#include"CEnemigo.h"
#include<vector>
using std::vector;

class CVector {

private:
	vector<CEnemigo*>arr_enemigo;

public:
	CVector(Graphics^ gr, int n) {
		Random r;
		for (int i = 0; i < n; i += 1) {
			insert_enemy(new CEnemigo(r.Next(0, gr->VisibleClipBounds.Width - 55), r.Next(0, gr->VisibleClipBounds.Height - 80), r.Next(2, 4)));
		}
	}
	~CVector() {
		for each (CEnemigo * _iterator in arr_enemigo) {
			delete _iterator;
		}
	}
	void insert_enemy(CEnemigo* enemy) {
		arr_enemigo.push_back(enemy);
	}
	void move(Graphics^ gr, CChrono* chrono) {
		for each (CEnemigo * _iterator in arr_enemigo) {
			_iterator->move(gr, chrono);
		}
	}
	void draw(Graphics^ gr, Bitmap^ btpEnemy) {
		for each (CEnemigo * _iterator in arr_enemigo) {
			_iterator->draw(gr, btpEnemy);
		}
	}
	void clear_emeny_vector() {
		for each (CEnemigo * _iterator in arr_enemigo) {
			delete _iterator;
		}
		arr_enemigo.clear();
	}
	/*Métodos de acceso.*/
	int get_enemy_size() { /*Obtener tamaño del vector enemigo.*/
		return arr_enemigo.size();
	}
	CEnemigo* get_enemy_at(int pos) { /*Obtener un enemigo en la posición indicada.*/
		return arr_enemigo.at(pos);
	}
};

#endif