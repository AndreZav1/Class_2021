#pragma once
#include"CControladora.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		CControladora* control;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
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
			this->Clock->Interval = 35;
			this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 645);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Clock_Tick(System::Object^ sender, System::EventArgs^ e) {

		g->Clear(Color::Pink);

		control->Mover(g);
		control->Pintar(g);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		Clock->Enabled = true;
	}
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		control->create_figure(e);
	}
	};
}
