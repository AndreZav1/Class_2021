#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

#include"CFantasma.h"
#include"CPacdot.h"
#include"CBonus.h"

#include<vector>
#include<ctime>
using std::vector;

class CVector {

private:
	vector<CFantasma*>fantasmas;
	vector<CPacdot*>pacdots;
	vector<CBonus*>bonus;

	int time_aparicion_bonus;
	int regresa_velocidad;

	int time_cooldown;
	bool cooldown;

	void colisiones(Graphics^ gr, CPacman* pacman) {

		for (int i = 0; i < pacdots.size(); i += 1) { /*Colisiones de pacman con pacdots.*/
			if (pacdots.at(i)->hit_box().IntersectsWith(pacman->area())) {
				pacdots.at(i)->set_visible(false);
				pacman->increase_points(1);
			}
		}
		for (int i = 0; i < fantasmas.size(); i += 1) { /*Colisiones de pacman con fantasmas.*/
			if (fantasmas.at(i)->area().IntersectsWith(pacman->area()) && !cooldown) {
				pacman->decrease_hp();
				pacman->regresa_inicio();

				cooldown = true;
				time_cooldown = time(0);
			}
		}
		if (difftime(time(0), time_cooldown) >= 2)cooldown = false;
		for (int i = 0; i < bonus.size(); i += 1) { /*Colisiones de pacman con los bonus.*/
			if (bonus.at(i)->area().IntersectsWith(pacman->area())) {
				bonus.at(i)->set_visible(false);
				pacman->set_speed(12);
				regresa_velocidad = time(0);
			}
		}
		if (difftime(time(0), regresa_velocidad) >= 5) {
			pacman->set_speed(5);
		}

		/*Evaluaciones.*/
		Random r;
		if (difftime(time(0), time_aparicion_bonus) >= 5) {
			bonus.clear();
			bonus.push_back(new CBonus(r.Next(0, (int)gr->VisibleClipBounds.Width - 80), r.Next(0, (int)gr->VisibleClipBounds.Height - 80), r.Next(0, 5)));
			time_aparicion_bonus = time(0);
		}
		for (int i = 0; i < pacdots.size(); i += 1) {
			if (!pacdots.at(i)->get_visible()) {
				pacdots.erase(pacdots.begin() + i);
			}
		}
		for (int i = 0; i < bonus.size(); i += 1) {
			if (!bonus.at(i)->get_visible()) {
				bonus.erase(bonus.begin() + i);
			}
		}
	}
public:
	CVector(Graphics^ gr, int cant_max_fantasmas, int cant_max_pacdots) {
		Random r;
		/*Agregando fantasmas.*/
		for (int i = 0; i < cant_max_fantasmas; i += 1) {
			fantasmas.push_back(new CFantasma(r.Next(0, (int)gr->VisibleClipBounds.Width - 40), r.Next(0, (int)gr->VisibleClipBounds.Height - 40), r.Next(0, 5), r.Next(3, 8)));
		}
		/*Agregando pacdots.*/
		for (int i = 0; i < cant_max_pacdots; i += 1) {
			CPacdot* pacdot = new CPacdot(r.Next(0, (int)gr->VisibleClipBounds.Width - 80), r.Next(0, (int)gr->VisibleClipBounds.Height - 80));
			if (!pacdot_colision(pacdot->area())) {
				pacdots.push_back(pacdot);
			}
			else
			{
				delete pacdot;
				i -= 1;
			}
		}
		/*Agregando bonus.*/
		bonus.push_back(new CBonus(r.Next(0, (int)gr->VisibleClipBounds.Width - 80), r.Next(0, (int)gr->VisibleClipBounds.Height - 80), r.Next(0, 5)));
		time_aparicion_bonus = time(0);
		cooldown = false;
	}
	~CVector() {
		for each (CFantasma * _iterator in fantasmas) {
			delete _iterator;
		}
		for each (CPacdot * _iterator in pacdots) {
			delete _iterator;
		}
		for each (CBonus * _iterator in bonus) {
			delete _iterator;
		}
	}
	void move(Graphics^ gr, CPacman* pacman) {
		for each (CFantasma * _iterator in fantasmas) {
			_iterator->move(gr);
		}
		for each (CPacdot * _iterator in pacdots) {
			_iterator->move(gr);
		}
		for each (CBonus * _iterator in bonus) {
			_iterator->move(gr);
		}
		colisiones(gr, pacman);
	}
	void draw(Graphics^ gr, Bitmap^ btpFantasma, Bitmap^ btpPacdots, Bitmap^ btpBonus) {
		for each (CFantasma * _iterator in fantasmas) {
			_iterator->draw(gr, btpFantasma);
		}
		for each (CPacdot * _iterator in pacdots) {
			_iterator->draw(gr, btpPacdots);
		}
		for each (CBonus * _iterator in bonus) {
			_iterator->draw(gr, btpBonus);
		}
	}
	/*Métodos de clase.*/
	bool pacdot_colision(Rectangle r) {
		for (int i = 0; i < pacdots.size(); i += 1) {
			if (pacdots.at(i)->area().IntersectsWith(r)) {
				return true;
			}
		}
		return false;
	}
	/*Métodos de acceso.*/
	int get_pacdot_size() {
		return pacdots.size();
	}
};

#endif