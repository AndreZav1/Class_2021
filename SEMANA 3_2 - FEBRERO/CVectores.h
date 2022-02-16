#pragma once
#ifndef CVECTORES_H
#define CVECTORES_H

#include"CPiedra.h"
#include<vector>

class CVectores {

private:
	std::vector<CPiedra*>arr_piedra;

	void insert_stone(CPiedra* stone) {
		arr_piedra.push_back(stone);
	}
public:
	CVectores(Graphics^ gr) {
		Random r;
		for (int i = 0; i < 4; i += 1) {
			CPiedra* piedra = new CPiedra(r.Next(0, (int)gr->VisibleClipBounds.Width - 300), r.Next(120, (int)gr->VisibleClipBounds.Height - 100));
			if (!collision_stone_(piedra->area())) {
				insert_stone(piedra);
			}
			else {
				delete piedra;
				i -= 1;
			}
		}
	}
	~CVectores() {
		for each (CPiedra * _iterator in arr_piedra) {
			delete _iterator;
		}
	}
	void draw(Graphics^ gr, Bitmap^ btpStone) {
		for each (CPiedra * _iterator in arr_piedra) {
			_iterator->draw(gr, btpStone);
		}
	}
	bool collision_stone_(Rectangle rec) {

		for (int i = 0; i < arr_piedra.size(); i += 1) {
			if (arr_piedra.at(i)->area().IntersectsWith(rec)) {
				return true;
			}
		}
		return false;
	}
};

#endif