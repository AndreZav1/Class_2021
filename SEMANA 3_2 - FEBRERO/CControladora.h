#pragma once
#ifndef CCONTROLADORA_H
#define CONTROLADORA_H

#include"CPersonaje.h"
#include"CVector.h"

using namespace System::Windows::Forms;

ref class CControladora {

private:
	/*Personaje*/
	CPersonaje* personaje;
	/*Vector*/
	CVector* vector;

	/*Bitmaps*/
	Bitmap^ btpPerso;
	Bitmap^ btpStone;
public:
	CControladora(Graphics^ gr) {
		/*Instanciando personaje.*/
		personaje = new CPersonaje(50, 50, 4, 3);
		/*Instanciando vector class.*/
		vector = new CVector(gr);
		/*Instanciando bitmaps.*/
		btpPerso = gcnew Bitmap("Recursos/MiniPersonajes.png");
		btpStone = gcnew Bitmap("Recursos/Piedra.png");
	}
	~CControladora() {
		delete personaje;
		delete vector;
	}

	void input(KeyEventArgs^ e, bool validate_movement) {

		int speed = 10;

		if (validate_movement) {

			if (e->KeyCode == Keys::W) {
				personaje->set_dy(-speed);
			}
			else
			{
				if (e->KeyCode == Keys::S) {
					personaje->set_dy(speed);
				}
				else
				{
					if (e->KeyCode == Keys::A) {
						personaje->set_dx(-speed);
					}
					else
					{
						if (e->KeyCode == Keys::D) {
							personaje->set_dx(speed);
						}
					}
				}
			}
		}
		else
		{
			if (e->KeyCode == Keys::W) {
				personaje->set_dy(0);
			}
			else
			{
				if (e->KeyCode == Keys::S) {
					personaje->set_dy(0);
				}
				else
				{
					if (e->KeyCode == Keys::A) {
						personaje->set_dx(0);
					}
					else
					{
						if (e->KeyCode == Keys::D) {
							personaje->set_dx(0);
						}
					}
				}
			}
		}
		
	}

	void move(Graphics^ gr) {

		if (!vector->collision_stone_(personaje->next_area())) {
			personaje->move(gr);
		}
	}
	void draw(Graphics^ gr) {
		personaje->draw(gr, btpPerso);
		vector->draw(gr, btpStone);
	}
};

#endif