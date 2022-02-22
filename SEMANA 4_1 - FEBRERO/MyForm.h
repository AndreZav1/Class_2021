#pragma once
#include"CControladora.h"

namespace Project1 {

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
			control = gcnew CControladora(gr);
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
		/*Canvas.*/
		Graphics^ gr;
		/*Buffered Graphics.*/
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		/*Controladora.*/
		CControladora^ control;
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
			this->ClientSize = System::Drawing::Size(709, 401);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion

		Void Clock_Tick(Object^ sender, EventArgs^ e) {
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(gr, this->ClientRectangle);

			/*Limpiar pantalla.*/
			buffer->Graphics->Clear(Color::LightBlue);

			control->move(buffer->Graphics);

			buffer->Render(gr);
			delete space;
			delete buffer;
		}
		Void MyForm_Load(Object^ sender, EventArgs^ e) {
			Clock->Interval = 38;
			Clock->Enabled = true;
		}
		Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
			control->input(e, true);
		}
		Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e) {
			control->input(e, false);
		}
	};
}
