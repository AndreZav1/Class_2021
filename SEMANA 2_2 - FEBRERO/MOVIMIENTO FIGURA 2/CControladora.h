#pragma once

#include"CCirculo.h"
#include"CCuadrado.h"
#include"CRectangulo.h"
#include"CElipse.h"
#include"CTriangulo.h"
#include"CRombo.h"

using System::Windows::Forms::KeyEventArgs;
using System::Windows::Forms::Keys;
using System::Windows::Forms::Form;

#include<vector>
#include<string>

using std::vector;
using std::string;

class CControladora {

private:
	vector<CCirculo*>arr_cir;
	vector<CCuadrado*>arr_cdr;
	vector<CRectangulo*>arr_rec;
	vector<CElipse*>arr_elip;
	vector<CTriangulo*>arr_tri;
	vector<CRombo*>arr_rombo;

	void crear_figura(Graphics^ g, string type) {

		Random r;
		if (type == "Circulo") {
			arr_cir.push_back(new CCirculo(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
		}
		else
		{
			if (type == "Cuadrado") {
				arr_cdr.push_back(new CCuadrado(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
			}
			else
			{
				if (type == "Rectangulo") {
					arr_rec.push_back(new CRectangulo(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
				}
				else
				{
					if (type == "Elipse") {
						arr_elip.push_back(new CElipse(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
					}
					else
					{
						if (type == "Triangulo") {
							arr_tri.push_back(new CTriangulo(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
						}
						else
						{
							if (type == "Rombo") {
								arr_rombo.push_back(new CRombo(r.Next(10, g->VisibleClipBounds.Width - 70), r.Next(10, g->VisibleClipBounds.Height - 70)));
							}
						}
					}
				}
			}
		}
	}
public:
	CControladora() {
	}
	~CControladora() {

		for each (CCirculo * _iterator in arr_cir) {
			delete _iterator;
		}
		for each (CCuadrado * _iterator in arr_cdr) {
			delete _iterator;
		}
		for each (CRectangulo * _iterator in arr_rec) {
			delete _iterator;
		}
		for each (CElipse * _iterator in arr_elip) {
			delete _iterator;
		}
		for each (CTriangulo * _iterator in arr_tri) {
			delete _iterator;
		}
		for each (CRombo * _iterator in arr_rombo) {
			delete _iterator;
		}
	}
	void input(KeyEventArgs^ e, Graphics^ g, Form^ f) {

		if (e->KeyCode == Keys::C) {
			crear_figura(g, "Circulo");
		}
		else
		{
			if (e->KeyCode == Keys::D) {
				crear_figura(g, "Cuadrado");
			}
			else
			{
				if (e->KeyCode == Keys::R) {
					crear_figura(g, "Rectangulo");
				}
				else
				{
					if (e->KeyCode == Keys::E) {
						crear_figura(g, "Elipse");
					}
					else
					{
						if (e->KeyCode == Keys::T) {
							crear_figura(g, "Triangulo");
						}
						else
						{
							if (e->KeyCode == Keys::Escape) {
								f->Close();
							}
							else
							{
								if (e->KeyCode == Keys::O) {
									crear_figura(g, "Rombo");
								}
							}
						}
					}
				}
			}
		}
	}
	void mover(Graphics^ g) {

		for each (CCirculo * _iterator in arr_cir) {
			_iterator->mover(g);
		}
		for each (CCuadrado * _iterator in arr_cdr) {
			_iterator->mover(g);
		}
		for each (CRectangulo * _iterator in arr_rec) {
			_iterator->mover(g);
		}
		for each (CElipse * _iterator in arr_elip) {
			_iterator->mover(g);
		}
		for each (CTriangulo * _iterator in arr_tri) {
			_iterator->mover(g);
		}
		for each (CRombo * _iterator in arr_rombo) {
			_iterator->mover(g);
		}
	}
	void pintar(Graphics^ g) {
		
		for each (CCirculo * _iterator in arr_cir) {
			_iterator->pintar(g);
		}
		for each (CCuadrado * _iterator in arr_cdr) {
			_iterator->pintar(g);
		}
		for each (CRectangulo * _iterator in arr_rec) {
			_iterator->pintar(g);
		}
		for each (CElipse * _iterator in arr_elip) {
			_iterator->pintar(g);
		}
		for each (CTriangulo * _iterator in arr_tri) {
			_iterator->pintar(g);
		}
		for each (CRombo * _iterator in arr_rombo) {
			_iterator->pintar(g);
		}
	}
};