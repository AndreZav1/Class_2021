#pragma once

#include"CControladora.h"

namespace SPRITE {

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
			control = new CControladora(gr , 10);
			btpAsh = gcnew Bitmap("Recursos/Ash.png");
			btpBala = gcnew Bitmap("Recursos/Bullet.png");
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
		CControladora* control;
		/*Buffere Graphics*/
		BufferedGraphicsContext^ space;
		BufferedGraphics^ bfr;
		/*Imagenes*/
		Bitmap^ btpAsh;
		Bitmap^ btpBala;

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
			this->ClientSize = System::Drawing::Size(502, 348);
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
			bfr = space->Allocate(gr, this->ClientRectangle);

			bfr->Graphics->Clear(Color::WhiteSmoke);

			control->mover(bfr->Graphics);
			control->pintar(bfr->Graphics, btpAsh, btpBala);

			bfr->Render(gr);

			if (control->you_win()) {
				Clock->Enabled = false;
				MessageBox::Show("\tGanaste!\t");
				Application::Exit();
			}
			if (control->you_defeat()) {
				Clock->Enabled = false;
				MessageBox::Show("\tPerdiste!\t");
				Application::Exit();
			}

			delete space;
			delete bfr;
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
			control->input(e, true);
		}
		Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e) {
			control->input(e, false);
		}
	};
}
