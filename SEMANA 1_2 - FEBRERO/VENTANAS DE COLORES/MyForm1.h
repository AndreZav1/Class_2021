#pragma once
#include"MyForm2.h"

namespace Project3 {

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
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			panel1->BackColor = Color::White;
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
		System::Windows::Forms::Button^ btn_Rojo;
	    System::Windows::Forms::Button^ btn_Random;
	    System::Windows::Forms::Button^ btn_Verde;
	    System::Windows::Forms::Button^ btn_predeterminado;
	    System::Windows::Forms::Panel^ panel1;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btn_Rojo = (gcnew System::Windows::Forms::Button());
			this->btn_Random = (gcnew System::Windows::Forms::Button());
			this->btn_Verde = (gcnew System::Windows::Forms::Button());
			this->btn_predeterminado = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btn_Rojo
			// 
			this->btn_Rojo->Location = System::Drawing::Point(30, 13);
			this->btn_Rojo->Name = L"btn_Rojo";
			this->btn_Rojo->Size = System::Drawing::Size(75, 23);
			this->btn_Rojo->TabIndex = 0;
			this->btn_Rojo->Text = L"ROJO";
			this->btn_Rojo->UseVisualStyleBackColor = true;
			this->btn_Rojo->Click += gcnew System::EventHandler(this, &MyForm::btn_Rojo_Click);
			// 
			// btn_Random
			// 
			this->btn_Random->Location = System::Drawing::Point(153, 12);
			this->btn_Random->Name = L"btn_Random";
			this->btn_Random->Size = System::Drawing::Size(75, 23);
			this->btn_Random->TabIndex = 1;
			this->btn_Random->Text = L"RANDOM";
			this->btn_Random->UseVisualStyleBackColor = true;
			this->btn_Random->Click += gcnew System::EventHandler(this, &MyForm::btn_Random_Click);
			// 
			// btn_Verde
			// 
			this->btn_Verde->Location = System::Drawing::Point(30, 53);
			this->btn_Verde->Name = L"btn_Verde";
			this->btn_Verde->Size = System::Drawing::Size(75, 23);
			this->btn_Verde->TabIndex = 2;
			this->btn_Verde->Text = L"VERDE";
			this->btn_Verde->UseVisualStyleBackColor = true;
			this->btn_Verde->Click += gcnew System::EventHandler(this, &MyForm::btn_Verde_Click);
			// 
			// btn_predeterminado
			// 
			this->btn_predeterminado->Location = System::Drawing::Point(153, 53);
			this->btn_predeterminado->Name = L"btn_predeterminado";
			this->btn_predeterminado->Size = System::Drawing::Size(75, 23);
			this->btn_predeterminado->TabIndex = 3;
			this->btn_predeterminado->Text = L"DEFAULT";
			this->btn_predeterminado->UseVisualStyleBackColor = true;
			this->btn_predeterminado->Click += gcnew System::EventHandler(this, &MyForm::btn_predeterminado_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(30, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(198, 28);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(262, 127);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btn_predeterminado);
			this->Controls->Add(this->btn_Verde);
			this->Controls->Add(this->btn_Random);
			this->Controls->Add(this->btn_Rojo);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void btn_Rojo_Click(System::Object^ sender, System::EventArgs^ e) {

		Form^ form_rojo = gcnew Form;
		form_rojo->BackColor = Color::Red;
		panel1->BackColor = Color::Red;
		form_rojo->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		form_rojo->ShowDialog();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btn_Verde_Click(System::Object^ sender, System::EventArgs^ e) {

		Form^ form_verde = gcnew Form;
		form_verde->BackColor = Color::Green;
		panel1->BackColor = Color::Green;
		form_verde->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		form_verde->ShowDialog();
	}
	private: System::Void btn_Random_Click(System::Object^ sender, System::EventArgs^ e) {

		Random^ r = gcnew Random;

		int _r = r->Next(25, 150);
		int _g = r->Next(25, 150);
		int _b = r->Next(25, 150);

		Form^ form_random = gcnew Form;
		form_random->BackColor = Color::FromArgb(_r, _g, _b);
		panel1->BackColor = Color::FromArgb(_r, _g, _b);
		form_random->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		form_random->ShowDialog();
	}
	private: System::Void btn_predeterminado_Click(System::Object^ sender, System::EventArgs^ e) {

		MyForm2^ form_2 = gcnew MyForm2;
		form_2->Show();
	}
    };
}
