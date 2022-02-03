#pragma once

namespace FORMULARIO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{

	private:
		String^ name;
		int presionado;

	public:
		MyForm1(void)
		{
			InitializeComponent();
			presionado = 0;
		}
	protected:

		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_pregunta;

	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::Button^ btn_Red;
	private: System::Windows::Forms::Button^ btn_Green;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lbl_pregunta = (gcnew System::Windows::Forms::Label());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_Red = (gcnew System::Windows::Forms::Button());
			this->btn_Green = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_pregunta
			// 
			this->lbl_pregunta->AutoSize = true;
			this->lbl_pregunta->Location = System::Drawing::Point(59, 73);
			this->lbl_pregunta->Name = L"lbl_pregunta";
			this->lbl_pregunta->Size = System::Drawing::Size(35, 13);
			this->lbl_pregunta->TabIndex = 0;
			this->lbl_pregunta->Text = L"label1";
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(189, 209);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(83, 40);
			this->btn_exit->TabIndex = 1;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = true;
			// 
			// btn_Red
			// 
			this->btn_Red->Location = System::Drawing::Point(38, 127);
			this->btn_Red->Name = L"btn_Red";
			this->btn_Red->Size = System::Drawing::Size(93, 35);
			this->btn_Red->TabIndex = 2;
			this->btn_Red->Text = L"Rojo";
			this->btn_Red->UseVisualStyleBackColor = true;
			this->btn_Red->Click += gcnew System::EventHandler(this, &MyForm1::btn_Red_Click);
			// 
			// btn_Green
			// 
			this->btn_Green->Location = System::Drawing::Point(157, 127);
			this->btn_Green->Name = L"btn_Green";
			this->btn_Green->Size = System::Drawing::Size(93, 35);
			this->btn_Green->TabIndex = 3;
			this->btn_Green->Text = L"Verde";
			this->btn_Green->UseVisualStyleBackColor = true;
			this->btn_Green->Click += gcnew System::EventHandler(this, &MyForm1::btn_Green_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btn_Green);
			this->Controls->Add(this->btn_Red);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->lbl_pregunta);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Void btn_Red_Click(Object^ sender, EventArgs^ e) {

			presionado = 1;
			this->Close();
		}
		Void btn_Green_Click(Object^ sender, EventArgs^ e) {
			presionado = 2;
			this->Close();
		}
	public:
		void colocar_nombre(String^ nombre) {
			lbl_pregunta->Text = nombre + " dime cual es tu color favorito.";
		}
		String^ get_respuesta() {
			if (presionado == 1) {
				return "Red";
			}
			else {
				if (presionado == 2) {
					return "Green";
				}
			}
		}
};
}
