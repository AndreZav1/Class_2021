#pragma once
#ifndef CCONTROLADORA_H
#define CCONTROLADORA_H

#include<fstream>
#include"CPacman.h"
#include"CVector.h"

using std::ifstream; using std::ofstream; using std::ios;
using System::Windows::Forms::KeyEventArgs; using System::Windows::Forms::Keys;

ref class CControladora {

private:
	/*Bitmaps*/
	Bitmap^ btpPacman;
	Bitmap^ btpFantasma;
	Bitmap^ btpPacdot;
	Bitmap^ btpBonus;
	/*Pacman.*/
	CPacman* pacman;
	/*Vector.*/
	CVector* vector;

	/*Variables.*/
	int pacman_hp; //Variable de vidas de pacman.
	int cant_max_fantasma; //Variable de cantidad máx. de fantasmas.
	int cant_max_pacdots; //Variable de cantidad máx. de pacdots.


	void draw(Graphics^ gr) {

		gr->DrawString("Vidas: " + pacman->get_hp(), gcnew System::Drawing::Font("Times New Roman", 14), gcnew System::Drawing::SolidBrush(Color::Black), 380, 10);
		gr->DrawString("Puntos: " + pacman->get_points(), gcnew System::Drawing::Font("Times New Roman", 14), gcnew System::Drawing::SolidBrush(Color::Black), 380, 30);
		pacman->draw(gr, btpPacman);
		vector->draw(gr, btpFantasma, btpPacdot, btpBonus);
	}
public:
	CControladora(Graphics^ gr) {
		load_data();
		/*Instanciando Pacman.*/
		btpPacman = gcnew Bitmap("Recursos/Pacman.png");
		pacman = new CPacman(50, 50, pacman_hp);

		btpFantasma = gcnew Bitmap("Recursos/Fantasma.png");
		btpPacdot = gcnew Bitmap("Recursos/pacdot.png");
		btpBonus = gcnew Bitmap("Recursos/superpacdots.png");

		/*Instanciando Vector.*/
		vector = new CVector(gr, cant_max_fantasma, cant_max_pacdots);

		/*Inicializando variables.*/
	}
	~CControladora() {
		delete pacman;
	}

	void input(KeyEventArgs^ e) {

		switch (e->KeyCode)
		{
		case Keys::Right: {
			pacman->set_dx(pacman->get_speed());
			pacman->set_dy(0);
		}break;
		case Keys::Left: {
			pacman->set_dx(-pacman->get_speed());
			pacman->set_dy(0);
		}break;
		case Keys::Up: {
			pacman->set_dy(-pacman->get_speed());
			pacman->set_dx(0);
		}break;
		case Keys::Down: {
			pacman->set_dy(pacman->get_speed());
			pacman->set_dx(0);
		}break;
		}
	}

	void move(Graphics^ gr) {
		pacman->move(gr);
		vector->move(gr, pacman);
		
		/*Draw.*/
		draw(gr);
	}
	bool finish_game() {

		if (pacman->get_hp() <= 0 || vector->get_pacdot_size() == 0) {
			return true;
		}
		return false;
	}
	void save_game() {

		ofstream file;
		file.open("OUTPUT.txt", ios::out);

		file << "PACDOTS ATRAPADOS: " << pacman->get_points();

		file.close();
	}
private:
	void load_data() {
		ifstream file;
		file.open("INPUT.txt", ios::in);

		/*Cargamos dato de la primera linea del archivo.*/
		int pacman_hp;
		file >> pacman_hp;
		this->pacman_hp = pacman_hp;
		/*Cargamos dato de la segunda linea del archivo.*/
		int cant_max_fantasma;
		file >> cant_max_fantasma;
		this->cant_max_fantasma = cant_max_fantasma;
		/*Cargamos dato de la tercera linea del archivo.*/
		int cant_max_pacdots;
		file >> cant_max_pacdots;
		this->cant_max_pacdots = cant_max_pacdots;

		file.close();
	}
};

#endif