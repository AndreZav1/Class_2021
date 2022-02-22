#pragma once
#ifndef CCONTROLADORA_H
#define CCONTROLADORA_H

#include"CChrono.h"
#include"CEnemigo.h"
#include"CVector.h"
#include<fstream>

using namespace System::Windows::Forms;
using namespace std;

ref class CControladora {

private:
	CChrono* chrono;
	CVector* vector;
	/*Bitmaps.*/
	Bitmap^ btpChrono;
	Bitmap^ btpEnemy;
public:
	CControladora(Graphics^ gr) {
		chrono = new CChrono(50, 50);
		vector = new CVector(gr, 5);
		/*Bitmaps.*/
		btpChrono = gcnew Bitmap("chrono.png");
		btpEnemy = gcnew Bitmap("enemy.png");
	}
	~CControladora() {
		save_data();
		delete chrono;
		delete vector;
	}

	void input(KeyEventArgs^ e, bool validate_movement) {

		int speed = 5;

		if (validate_movement) {

			switch (e->KeyCode)
			{
			case Keys::A: {
				chrono->set_dx(-speed);
			}break;
			case Keys::D: {
				chrono->set_dx(speed);
			}break;
			case Keys::W: {
				chrono->set_dy(-speed);
			}break;
			case Keys::S: {
				chrono->set_dy(speed);
			}break;
			case Keys::G: {
				save_data();
				MessageBox::Show("\tDatos Guardados!\t");
			}break;
			case Keys::L: {
				load_data();
				MessageBox::Show("\tDatos Cargados!\t");
			}break;
			}
		}
		else
		{
			switch (e->KeyCode)
			{
			case Keys::A: {
				chrono->set_dx(0);
			}break;
			case Keys::D: {
				chrono->set_dx(0);
			}break;
			case Keys::W: {
				chrono->set_dy(0);
			}break;
			case Keys::S: {
				chrono->set_dy(0);
			}break;
			}
		}
	}

	void move(Graphics^ gr) {
		chrono->move(gr);
		vector->move(gr, chrono);

		/*Draw*/
		draw(gr);
	}
	void draw(Graphics^ gr) {
		chrono->draw(gr, btpChrono);
		vector->draw(gr, btpEnemy);
	}
private:
	void save_data() {

		ofstream file;
		file.open("Data.txt", ios::out);

		file << chrono->get_x() << " " << chrono->get_y() << " " << chrono->get_idy() << " " << chrono->get_idx() << endl;
		file << vector->get_enemy_size() << endl;
		for (int i = 0; i < vector->get_enemy_size(); i += 1) {
			file << vector->get_enemy_at(i)->get_x() << " " << vector->get_enemy_at(i)->get_y() << " " << vector->get_enemy_at(i)->get_idx() << " " << vector->get_enemy_at(i)->get_idy() << " " << vector->get_enemy_at(i)->get_dx() << " " << vector->get_enemy_at(i)->get_dy() << " " << vector->get_enemy_at(i)->get_type() << endl;
		}

		file.close();
	}
	void load_data() {

		ifstream file;
		file.open("Data.txt", ios::in);

		int x, y, idx, idy;
		file >> x >> y >> idx >> idy;
		chrono->set_x(x); chrono->set_y(y); chrono->set_idx(idx); chrono->set_idy(idy);
		int size;
		file >> size;

		vector->clear_emeny_vector();
		for (int i = 0; i < size; i += 1) {
			int dx, dy, type;
			file >> x >> y >> idx >> idx >> dx >> dy >> type;
			vector->insert_enemy(new CEnemigo(x, y, dx, dy, idx, idy, type));
		}

		file.close();
	}
};

#endif