#pragma once
#include<conio.h>

#include"CVacuna.h"
#include"CMonigote.h"
#include"CMU.h"
#include"CDelta.h"

#include<vector>
#include<ctime>

class CControladora {

private:
	/*Vacuna.*/
	CVacuna* vacuna;
	/*Monigotes.*/
	vector<CMonigote*>Cmonigotes;
	/*Virus.*/
	vector<CMU*>vMU;
	vector<CDelta*>vDelta;

	/*Capturador de tiempo.*/
	int time_aparecer_virus;

	/*contador de monigotes eliminados por virus*/
	int cont_eliminados_virus;
	/*contador de monigotes salvados por la vacuna*/
	int cont_salvados_vacuna;

	void aparecer_virus(int widthS, int heightS) {

		Random r;
		if (difftime(time(0), time_aparecer_virus) >= 5) {
			int n = r.Next(0, 2);
			if (n == 0) {
				vMU.push_back(new CMU(r.Next(5, widthS - 12), r.Next(5, heightS - 6), 10));
			}
			else {
				vDelta.push_back(new CDelta(r.Next(5, widthS - 12), r.Next(5, heightS - 15), 12));
			}
			time_aparecer_virus = time(0);
		}
	}
	void Validaciones_y_Colisiones() {

		/*Colisiones entre variante Delta y los monigotes.*/
		for (int i = 0; i < vDelta.size(); i += 1) {
			for (int j = 0; j < Cmonigotes.size(); j += 1) {
				if (vDelta.at(i)->area().IntersectsWith(Cmonigotes.at(j)->area())) {

					if (Cmonigotes.at(j)->get_color() == 15) {

						Cmonigotes.at(j)->set_color(12);
						Cmonigotes.at(j)->set_dx(0);
						Cmonigotes.at(j)->set_dy(0);
					}
				}
			}
		}
		/*Colisiones entre variante MU y los monigotes contagios de variante Delta.*/
		for (int i = 0; i < vMU.size(); i += 1) {
			for (int j = 0; j < Cmonigotes.size(); j += 1) {
				if (vMU.at(i)->area().IntersectsWith(Cmonigotes.at(j)->area())) {

					if (Cmonigotes.at(j)->get_color() == 12) {
						Cmonigotes.erase(Cmonigotes.begin() + j);
						cont_eliminados_virus += 1;
					}
				}
			}
		}
		/*Colision entre variante MU y los monigotes.*/
		for (int i = 0; i < vMU.size(); i += 1) {
			for (int j = 0; j < Cmonigotes.size(); j += 1) {
				if (vMU.at(i)->area().IntersectsWith(Cmonigotes.at(j)->area())) {

					if (Cmonigotes.at(j)->get_color() == 15) {
						Cmonigotes.at(j)->set_color(10);
					}
				}
			}
		}
		//for (int i = 0; i < vMU.size(); i += 1) {
		//	for (int j = 0; j < Cmonigotes.size(); j += 1) {
		//		if (vMU.at(i)->area().IntersectsWith(Cmonigotes.at(j)->area())) {
		//
		//			if (Cmonigotes.at(j)->get_color() == 10) {
		//				Cmonigotes.erase(Cmonigotes.begin() + j);
		//				cont_eliminados_virus += 1;
		//			}
		//		}
		//	}
		//}
		for (int i = 0; i < Cmonigotes.size(); i += 1) {
			if (Cmonigotes.at(i)->area().IntersectsWith(vacuna->area())) {
				if (Cmonigotes.at(i)->get_color() == 12 || Cmonigotes.at(i)->get_color() == 10 || Cmonigotes.at(i)->get_color() == 15) {

					Cmonigotes.at(i)->set_color(15);
					Cmonigotes.erase(Cmonigotes.begin() + i);
					cont_salvados_vacuna += 1;
				}
			}
		}
		for (int i = 0; i < vDelta.size(); i += 1) {
			for (int j = 0; j < Cmonigotes.size(); j += 1) {

				if (Cmonigotes.at(j)->get_color() == 10) {
					Cmonigotes.erase(Cmonigotes.begin() + j);
					cont_eliminados_virus += 1;
				}
			}
		}
	}
public:
	CControladora(int widthS, int heightS) {
		Random r;
		//Instanciar los 15 monigotes.
		for (int i = 0; i < 15; i += 1) {
			Cmonigotes.push_back(new CMonigote(r.Next(5, widthS - 10), r.Next(5, heightS - 15), 15));
		}
		vacuna = new CVacuna(r.Next(5, widthS - 10), r.Next(heightS - 30, heightS - 5), 9);
		time_aparecer_virus = time(0);
		cont_eliminados_virus = 0;
		cont_salvados_vacuna = 0;
	}
	~CControladora() {
		for each (CMonigote * _iterator in Cmonigotes) {
			delete _iterator;
		}
	}
	void Input(char key) {

		key = _getch();

		int speed = 1;

		switch (toupper(key))
		{
		case 'A': {
			vacuna->set_dx(-speed);
			vacuna->set_dy(0);
		}break;

		case 'D': {
			vacuna->set_dx(speed);
			vacuna->set_dy(0);
		}break;

		case 'W': {
			vacuna->set_dy(-speed);
			vacuna->set_dx(0);
		}break;

		case 'S': {
			vacuna->set_dy(speed);
			vacuna->set_dx(0);
		}break;
		}
	}
	void Borrar() {
		for (int i = 0; i < Cmonigotes.size(); i += 1) {
			Cmonigotes.at(i)->Borrar();
		}
		for (int i = 0; i < vMU.size(); i += 1) {
			vMU.at(i)->Borrar();
		}
		for (int i = 0; i < vDelta.size(); i += 1) {
			vDelta.at(i)->Borrar();
		}
		vacuna->Borrar();
	}
	void Mover(int widthS, int heightS) {

		Validaciones_y_Colisiones();
		aparecer_virus(widthS, heightS);

		for (int i = 0; i < Cmonigotes.size(); i += 1) {
			Cmonigotes.at(i)->Mover(widthS, heightS);
		}
		for (int i = 0; i < vMU.size(); i += 1) {
			vMU.at(i)->Mover(widthS, heightS);
		}
		for (int i = 0; i < vDelta.size(); i += 1) {
			vDelta.at(i)->Mover(widthS, heightS);
		}
		vacuna->Mover(widthS, heightS);
	}
	void Pintar() {

		Console::SetCursorPosition(0, 0);
		cout << "Virus eliminados por la variante delta: " << cont_eliminados_virus;
		Console::SetCursorPosition(0, 1);
		cout << "Monigotes salvador por la vacuna: " << cont_salvados_vacuna;

		for (int i = 0; i < Cmonigotes.size(); i += 1) {
			Cmonigotes.at(i)->Pintar();
		}
		for (int i = 0; i < vMU.size(); i += 1) {
			vMU.at(i)->Pintar();
		}
		for (int i = 0; i < vDelta.size(); i += 1) {
			vDelta.at(i)->Pintar();
		}
		vacuna->Pintar();
	}

	bool you_defeat() {

		for (int i = 0; i < vDelta.size(); i += 1) {
			if (vDelta.at(i)->area().IntersectsWith(vacuna->area())) {
				return true;
			}
		}
		for (int i = 0; i < vMU.size(); i += 1) {
			if (vMU.at(i)->area().IntersectsWith(vacuna->area())) {
				return true;
			}
		}
		return false;
	}
	int get_monigotes_perdidos() {
		return cont_eliminados_virus;
	}
	int get_monigotes_salvados() {
		return cont_salvados_vacuna;
	}
};

