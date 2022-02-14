#pragma once

#include"CControladora.h"

namespace SPRITE1 {

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
			control = new CControladora(10, gr);
			btpAsh = gcnew Bitmap("Ash.png");
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
		/*Bufered Graphics.*/
		BufferedGraphicsContext^ space;
		BufferedGraphics^ bf;

		CControladora* control;

		/*Obteniendo imagenes.*/
		Bitmap^ btpAsh;

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
			this->ClientSize = System::Drawing::Size(677, 448);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion

		Void MyForm_Load(Object^ sender, EventArgs^ e) {
			Clock->Interval = 38;
			Clock->Enabled = true;
		}
		Void Clock_Tick(Object^ sender, EventArgs^ e) {

			space = BufferedGraphicsManager::Current;
			bf = space->Allocate(gr, this->ClientRectangle);

			bf->Graphics->Clear(Color::White);

			control->mover(bf->Graphics);
			control->pintar(bf->Graphics, btpAsh);

			bf->Render(gr);


			if (control->you_win()) {
				Clock->Enabled = false;
				MessageBox::Show("\t¡Ganaste!\t");
				Application::Exit();
			}
			if (control->you_defeat()) {
				Clock->Enabled = false;
				MessageBox::Show("\t¡Perdiste!\t");
				Application::Exit();
			}

			delete space;
			delete bf;
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {

			control->input(e, true);
		}
		Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e) {

			control->input(e, false);
		}
	};
}
