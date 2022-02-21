#pragma once
#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include"CChrono.h"
#include"CVector.h"
#include<fstream>

using namespace System::Windows::Forms;
using namespace std;

ref class CController {

private:
	CVector* vector;
	CChrono* chrono;
	/*Bitmaps.*/
	Bitmap^ btpChrono;
	Bitmap^ btpEnemy;

public:
	CController(Graphics^ gr) {
		chrono = new CChrono(50, 50);
		vector = new CVector(gr, 2);
		btpChrono = gcnew Bitmap("chrono.png");
		btpEnemy = gcnew Bitmap("enemy.png");
	}
	~CController() {
		delete chrono;
		delete vector;
	}
	void input(KeyEventArgs^ e, bool validate_movement) {

		int speed = 10;

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
				MessageBox::Show("\tDatos guadados!\t");
			}break;
			case Keys::L: {
				load_data();
				MessageBox::Show("\tDatos cargados!\t");
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
		file.open("Datos.txt", ios::out);

		file << chrono->get_x() << " " << chrono->get_y() << " " << chrono->get_idx() << " " << chrono->get_idy() << endl;
		file << vector->get_enemy_size() << endl;
		for (int i = 0; i < vector->get_enemy_size(); i += 1) {
			file << vector->get_enemy(i)->get_x() << " " << vector->get_enemy(i)->get_y() << endl;
		}

		file.close();
	}
	void load_data() {

		ifstream file;
		file.open("Datos.txt", ios::in);

		int x, y, idx, idy;
		file >> x >> y >> idx >> idy;
		chrono->set_x(x); chrono->set_y(y); chrono->set_idy(idx); chrono->set_idy(idy);
		int size;
		file >> size;

		vector->clear_enemy_vector();
		for (int i = 0; i < size; i += 1) {
			file >> x, y;
			vector->insert_enemy(new CEnemigo(x, y));
		}

		file.close();
	}
};
#endif