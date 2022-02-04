#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TextBox^ textBox1;
	    System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	    System::Windows::Forms::TextBox^ textBox2;
	    System::Windows::Forms::TextBox^ textBox3;
	    System::Windows::Forms::Label^ lbl_r;
	    System::Windows::Forms::Label^ lbl_a;
	    System::Windows::Forms::Label^ lbl_v;
	    System::Windows::Forms::Button^ btn_aceptar;
	    System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_r = (gcnew System::Windows::Forms::Label());
			this->lbl_a = (gcnew System::Windows::Forms::Label());
			this->lbl_v = (gcnew System::Windows::Forms::Label());
			this->btn_aceptar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(128, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(128, 87);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(128, 141);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			// 
			// lbl_r
			// 
			this->lbl_r->AutoSize = true;
			this->lbl_r->Location = System::Drawing::Point(33, 48);
			this->lbl_r->Name = L"lbl_r";
			this->lbl_r->Size = System::Drawing::Size(36, 13);
			this->lbl_r->TabIndex = 4;
			this->lbl_r->Text = L"ROJO";
			// 
			// lbl_a
			// 
			this->lbl_a->AutoSize = true;
			this->lbl_a->Location = System::Drawing::Point(33, 148);
			this->lbl_a->Name = L"lbl_a";
			this->lbl_a->Size = System::Drawing::Size(35, 13);
			this->lbl_a->TabIndex = 5;
			this->lbl_a->Text = L"AZUL";
			// 
			// lbl_v
			// 
			this->lbl_v->AutoSize = true;
			this->lbl_v->Location = System::Drawing::Point(33, 94);
			this->lbl_v->Name = L"lbl_v";
			this->lbl_v->Size = System::Drawing::Size(44, 13);
			this->lbl_v->TabIndex = 6;
			this->lbl_v->Text = L"VERDE";
			// 
			// btn_aceptar
			// 
			this->btn_aceptar->Location = System::Drawing::Point(85, 198);
			this->btn_aceptar->Name = L"btn_aceptar";
			this->btn_aceptar->Size = System::Drawing::Size(75, 23);
			this->btn_aceptar->TabIndex = 7;
			this->btn_aceptar->Text = L"ACEPTAR";
			this->btn_aceptar->UseVisualStyleBackColor = true;
			this->btn_aceptar->Click += gcnew System::EventHandler(this, &MyForm2::btn_aceptar_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(267, 233);
			this->Controls->Add(this->btn_aceptar);
			this->Controls->Add(this->lbl_v);
			this->Controls->Add(this->lbl_a);
			this->Controls->Add(this->lbl_r);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btn_aceptar_Click(System::Object^ sender, System::EventArgs^ e) {

		int r = Convert::ToInt32(textBox1->Text);
		int g = Convert::ToInt32(textBox2->Text);
		int b = Convert::ToInt32(textBox3->Text);


		Form^ form_default = gcnew Form;
		form_default->BackColor = Color::FromArgb(r, g, b);
		form_default->ShowDialog();
	}
    };
}
