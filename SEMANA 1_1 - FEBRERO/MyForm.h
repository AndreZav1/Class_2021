#pragma once
#include"MyForm1.h"

namespace FORMULARIO {

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
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Exit;
	protected:

	private: System::Windows::Forms::TextBox^ tbx_palabra;
	private: System::Windows::Forms::Button^ btn_Preguntar;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btn_Exit = (gcnew System::Windows::Forms::Button());
			this->tbx_palabra = (gcnew System::Windows::Forms::TextBox());
			this->btn_Preguntar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_Exit
			// 
			this->btn_Exit->Location = System::Drawing::Point(191, 263);
			this->btn_Exit->Name = L"btn_Exit";
			this->btn_Exit->Size = System::Drawing::Size(95, 39);
			this->btn_Exit->TabIndex = 0;
			this->btn_Exit->Text = L"Exit";
			this->btn_Exit->UseVisualStyleBackColor = true;
			this->btn_Exit->Click += gcnew System::EventHandler(this, &MyForm::btn_Exit_Click);
			// 
			// tbx_palabra
			// 
			this->tbx_palabra->Location = System::Drawing::Point(75, 86);
			this->tbx_palabra->Name = L"tbx_palabra";
			this->tbx_palabra->Size = System::Drawing::Size(135, 20);
			this->tbx_palabra->TabIndex = 2;
			// 
			// btn_Preguntar
			// 
			this->btn_Preguntar->Location = System::Drawing::Point(96, 131);
			this->btn_Preguntar->Name = L"btn_Preguntar";
			this->btn_Preguntar->Size = System::Drawing::Size(95, 39);
			this->btn_Preguntar->TabIndex = 3;
			this->btn_Preguntar->Text = L"Preguntar";
			this->btn_Preguntar->UseVisualStyleBackColor = true;
			this->btn_Preguntar->Click += gcnew System::EventHandler(this, &MyForm::btn_Send_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->tbx_palabra);
			this->panel1->Controls->Add(this->btn_Preguntar);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(295, 312);
			this->panel1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(127, 190);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(298, 314);
			this->Controls->Add(this->btn_Exit);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		Void btn_Send_Click(Object^ sender, EventArgs^ e) {

			MyForm1^ FORMULARIO_2 = gcnew MyForm1;
			FORMULARIO_2->colocar_nombre(tbx_palabra->Text);
			FORMULARIO_2->ShowDialog();
			String^ respuesta = FORMULARIO_2->get_respuesta();

			label1->Text = respuesta;
	    }
	private: System::Void btn_Exit_Click(System::Object^ sender, System::EventArgs^ e) {

		Application::Exit();
	}
	};
}
