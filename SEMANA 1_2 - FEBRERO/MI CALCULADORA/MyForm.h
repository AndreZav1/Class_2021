#pragma once

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
		float num1;
		float num2;
		float resp;

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = "Mi Calculadora";
			num1 = 0.0f;
			num2 = 0.0f;
			resp = 0.0f;
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
		System::Windows::Forms::Label^ lbl_calculadora;
	    System::Windows::Forms::TextBox^ tbx_num1;
	    System::Windows::Forms::TextBox^ tbx_num2;
	    System::Windows::Forms::Label^ lbl_num1;
	    System::Windows::Forms::Label^ lbl_num2;
	    System::Windows::Forms::TextBox^ tbx_respuesta;
	    System::Windows::Forms::Label^ lbl_respuesta;
	    System::Windows::Forms::Button^ btn_Calcular;
	    System::Windows::Forms::Button^ btn_Suma;
	    System::Windows::Forms::Button^ btn_resta;
	    System::Windows::Forms::Button^ btn_multi;
	    System::Windows::Forms::Button^ btn_div;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lbl_calculadora = (gcnew System::Windows::Forms::Label());
			this->tbx_num1 = (gcnew System::Windows::Forms::TextBox());
			this->tbx_num2 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_num1 = (gcnew System::Windows::Forms::Label());
			this->lbl_num2 = (gcnew System::Windows::Forms::Label());
			this->tbx_respuesta = (gcnew System::Windows::Forms::TextBox());
			this->lbl_respuesta = (gcnew System::Windows::Forms::Label());
			this->btn_Calcular = (gcnew System::Windows::Forms::Button());
			this->btn_Suma = (gcnew System::Windows::Forms::Button());
			this->btn_resta = (gcnew System::Windows::Forms::Button());
			this->btn_multi = (gcnew System::Windows::Forms::Button());
			this->btn_div = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_calculadora
			// 
			this->lbl_calculadora->AutoSize = true;
			this->lbl_calculadora->Location = System::Drawing::Point(113, 19);
			this->lbl_calculadora->Name = L"lbl_calculadora";
			this->lbl_calculadora->Size = System::Drawing::Size(86, 13);
			this->lbl_calculadora->TabIndex = 0;
			this->lbl_calculadora->Text = L"CALCULADORA";
			// 
			// tbx_num1
			// 
			this->tbx_num1->Location = System::Drawing::Point(166, 66);
			this->tbx_num1->Name = L"tbx_num1";
			this->tbx_num1->Size = System::Drawing::Size(100, 20);
			this->tbx_num1->TabIndex = 1;
			// 
			// tbx_num2
			// 
			this->tbx_num2->Location = System::Drawing::Point(166, 111);
			this->tbx_num2->Name = L"tbx_num2";
			this->tbx_num2->Size = System::Drawing::Size(100, 20);
			this->tbx_num2->TabIndex = 2;
			// 
			// lbl_num1
			// 
			this->lbl_num1->AutoSize = true;
			this->lbl_num1->Location = System::Drawing::Point(59, 69);
			this->lbl_num1->Name = L"lbl_num1";
			this->lbl_num1->Size = System::Drawing::Size(53, 13);
			this->lbl_num1->TabIndex = 3;
			this->lbl_num1->Text = L"Numero 1";
			// 
			// lbl_num2
			// 
			this->lbl_num2->AutoSize = true;
			this->lbl_num2->Location = System::Drawing::Point(59, 114);
			this->lbl_num2->Name = L"lbl_num2";
			this->lbl_num2->Size = System::Drawing::Size(53, 13);
			this->lbl_num2->TabIndex = 4;
			this->lbl_num2->Text = L"Numero 2";
			// 
			// tbx_respuesta
			// 
			this->tbx_respuesta->Location = System::Drawing::Point(103, 237);
			this->tbx_respuesta->Name = L"tbx_respuesta";
			this->tbx_respuesta->Size = System::Drawing::Size(108, 20);
			this->tbx_respuesta->TabIndex = 5;
			// 
			// lbl_respuesta
			// 
			this->lbl_respuesta->AutoSize = true;
			this->lbl_respuesta->Location = System::Drawing::Point(124, 211);
			this->lbl_respuesta->Name = L"lbl_respuesta";
			this->lbl_respuesta->Size = System::Drawing::Size(58, 13);
			this->lbl_respuesta->TabIndex = 6;
			this->lbl_respuesta->Text = L"Respuesta";
			// 
			// btn_Calcular
			// 
			this->btn_Calcular->Location = System::Drawing::Point(116, 281);
			this->btn_Calcular->Name = L"btn_Calcular";
			this->btn_Calcular->Size = System::Drawing::Size(83, 33);
			this->btn_Calcular->TabIndex = 7;
			this->btn_Calcular->Text = L"Calcular";
			this->btn_Calcular->UseVisualStyleBackColor = true;
			this->btn_Calcular->Click += gcnew System::EventHandler(this, &MyForm::btn_Calcular_Click);
			// 
			// btn_Suma
			// 
			this->btn_Suma->Location = System::Drawing::Point(12, 153);
			this->btn_Suma->Name = L"btn_Suma";
			this->btn_Suma->Size = System::Drawing::Size(53, 43);
			this->btn_Suma->TabIndex = 8;
			this->btn_Suma->Text = L"+";
			this->btn_Suma->UseVisualStyleBackColor = true;
			this->btn_Suma->Click += gcnew System::EventHandler(this, &MyForm::btn_Suma_Click);
			// 
			// btn_resta
			// 
			this->btn_resta->Location = System::Drawing::Point(103, 153);
			this->btn_resta->Name = L"btn_resta";
			this->btn_resta->Size = System::Drawing::Size(53, 43);
			this->btn_resta->TabIndex = 9;
			this->btn_resta->Text = L"--";
			this->btn_resta->UseVisualStyleBackColor = true;
			this->btn_resta->Click += gcnew System::EventHandler(this, &MyForm::btn_resta_Click);
			// 
			// btn_multi
			// 
			this->btn_multi->Location = System::Drawing::Point(180, 153);
			this->btn_multi->Name = L"btn_multi";
			this->btn_multi->Size = System::Drawing::Size(53, 43);
			this->btn_multi->TabIndex = 10;
			this->btn_multi->Text = L"X";
			this->btn_multi->UseVisualStyleBackColor = true;
			this->btn_multi->Click += gcnew System::EventHandler(this, &MyForm::btn_multi_Click);
			// 
			// btn_div
			// 
			this->btn_div->Location = System::Drawing::Point(264, 153);
			this->btn_div->Name = L"btn_div";
			this->btn_div->Size = System::Drawing::Size(53, 43);
			this->btn_div->TabIndex = 11;
			this->btn_div->Text = L"/";
			this->btn_div->UseVisualStyleBackColor = true;
			this->btn_div->Click += gcnew System::EventHandler(this, &MyForm::btn_div_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 326);
			this->Controls->Add(this->btn_div);
			this->Controls->Add(this->btn_multi);
			this->Controls->Add(this->btn_resta);
			this->Controls->Add(this->btn_Suma);
			this->Controls->Add(this->btn_Calcular);
			this->Controls->Add(this->lbl_respuesta);
			this->Controls->Add(this->tbx_respuesta);
			this->Controls->Add(this->lbl_num2);
			this->Controls->Add(this->lbl_num1);
			this->Controls->Add(this->tbx_num2);
			this->Controls->Add(this->tbx_num1);
			this->Controls->Add(this->lbl_calculadora);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btn_Suma_Click(System::Object^ sender, System::EventArgs^ e) {

		num1 = Convert::ToSingle(tbx_num1->Text);
		num2 = Convert::ToSingle(tbx_num2->Text);

		resp = num1 + num2;
	}
	private: System::Void btn_Calcular_Click(System::Object^ sender, System::EventArgs^ e) {

		tbx_respuesta->Text = Convert::ToString(resp);
	}
	private: System::Void btn_resta_Click(System::Object^ sender, System::EventArgs^ e) {

		num1 = Convert::ToSingle(tbx_num1->Text);
		num2 = Convert::ToSingle(tbx_num2->Text);

		resp = num1 - num2;
	}
	private: System::Void btn_multi_Click(System::Object^ sender, System::EventArgs^ e) {

		num1 = Convert::ToSingle(tbx_num1->Text);
		num2 = Convert::ToSingle(tbx_num2->Text);

		resp = num1 * num2;
	}
	private: System::Void btn_div_Click(System::Object^ sender, System::EventArgs^ e) {
	
		num1 = Convert::ToSingle(tbx_num1->Text);
		num2 = Convert::ToSingle(tbx_num2->Text);
		if (num2 != 0) {

			resp = num1 / num2;
		}
		else {
			MessageBox::Show("Error!");
			resp = 0.0f;
		}
	}
    };
}
