#pragma once

#include"CController.h"

namespace CARRERA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			control = new CController();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete control;
		}
	private: 
		Graphics^ gr;
		CController* control;
		System::Windows::Forms::Timer^ Clock;
        System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Clock
			// 
			this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 461);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

		Void MyForm_Load(Object^ sender, EventArgs^ e) {

			Clock->Interval = 38;
			Clock->Enabled = true;
		}
		Void Clock_Tick(Object^ sender, EventArgs^ e) {

			gr->Clear(Color::WhiteSmoke);

			control->mover(gr);
			control->pintar(gr);

			if (control->terminar_carrera()) {
				Clock->Enabled = false;
				MessageBox::Show("Victorias:\n\nRectangulo: " + control->get_rectangle()->get_victorias() + "\n" +
					"Circulo: " + control->get_circle()->get_victorias() + "\n" + "Rombo: " + control->get_diamond()->get_victorias());
				this->Close();
			}
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
			control->input(e);
		}
	};
}
