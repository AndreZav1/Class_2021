#pragma once

#include"CControladora.h"

namespace CLASEMIERCOLES {

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
			panel1->BackColor = Color::White;
			gr = panel1->CreateGraphics();
			control = new CControladora();
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
		/*Canvas*/
		Graphics^ gr;
		/*Controladora*/
		CControladora* control;

		System::Windows::Forms::Panel^ panel1;
	    System::Windows::Forms::Timer^ Clock;
	    System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(747, 524);
			this->panel1->TabIndex = 0;
			// 
			// Clock
			// 
			this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 522);
			this->Controls->Add(this->panel1);
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
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {

			control->input(e, gr, this);
		}
	};
}
