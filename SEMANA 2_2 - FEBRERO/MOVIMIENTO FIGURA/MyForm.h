#pragma once

#include"CControladora.h"

namespace CLASEMIERCOLES2 {

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
			/*Creando el canvas en el panel_1*/
			g = pnl_1->CreateGraphics();
			pnl_1->Size = System::Drawing::Size(this->Width, this->Height);
			pnl_1->BackColor = Color::White;
			/*Instanciando controladora*/
			control = new CControladora();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/*Canvas.*/
		Graphics^ g;
		/*Controladora.*/
		CControladora* control;

	    System::Windows::Forms::Panel^ pnl_1;
	private: System::Windows::Forms::Timer^ Clock;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnl_1 = (gcnew System::Windows::Forms::Panel());
			this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnl_1
			// 
			this->pnl_1->Location = System::Drawing::Point(-1, 0);
			this->pnl_1->Name = L"pnl_1";
			this->pnl_1->Size = System::Drawing::Size(754, 499);
			this->pnl_1->TabIndex = 0;
			// 
			// Clock
			// 
			this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 498);
			this->Controls->Add(this->pnl_1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_ReSize);
			this->ResumeLayout(false);

		}
#pragma endregion

		Void MyForm_Load(Object^ sender, EventArgs^ e) {

			Clock->Enabled = true;
			Clock->Interval = 38;
		}
		Void Clock_Tick(Object^ sender, EventArgs^ e) {

			g->Clear(Color::Cyan);

			control->mover(g);
			control->pintar(g);
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
			control->input(e, g, this);
		}
		Void MyForm_ReSize(Object^ sender, EventArgs^ e) {

			g = pnl_1->CreateGraphics();
			pnl_1->Size = System::Drawing::Size(this->Width, this->Height);
		}
	};
}
