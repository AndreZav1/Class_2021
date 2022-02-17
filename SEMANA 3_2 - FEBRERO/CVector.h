#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

#include"CPiedra.h"
#include<vector>

using namespace System;

class CVector {

private:
	std::vector<CPiedra*>arr_stone;

	void insert_stone(CPiedra* stone) {
		arr_stone.push_back(stone);
	}
public:
	CVector(Graphics^ gr) {
		Random r;
		for (int i = 0; i < 4; i += 1) {
			CPiedra* stone = new CPiedra(r.Next(0, (int)gr->VisibleClipBounds.Width - 100), r.Next(100, (int)gr->VisibleClipBounds.Height - 100));
			if (!collision_stone_(stone->area())) {
				insert_stone(stone);
			}
			else
			{
				delete stone;
				i -= 1;
		    }
		}
	}
	~CVector() {
		for each (CPiedra * _iterator in arr_stone) {
			delete _iterator;
		}
	}
	void draw(Graphics^ gr, Bitmap^ btpStone) {
		for each (CPiedra * _iterator in arr_stone) {
			_iterator->draw(gr, btpStone);
		}
	}
	bool collision_stone_(Rectangle rec) {

		for (int i = 0; i < arr_stone.size(); i += 1) {
			if (arr_stone.at(i)->area().IntersectsWith(rec)) {
				return true;
			}
		}
		return false;
	}
};

#endif