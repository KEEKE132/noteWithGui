#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include "note.h"

namespace form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: Note* note;
	public:
		MyForm(Note* n)
		{
			InitializeComponent();
			note = n;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ Confirm;

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Confirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1276, 593);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// Confirm
			// 
			this->Confirm->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Confirm->ForeColor = System::Drawing::Color::Blue;
			this->Confirm->Location = System::Drawing::Point(499, 622);
			this->Confirm->Name = L"Confirm";
			this->Confirm->Size = System::Drawing::Size(216, 63);
			this->Confirm->TabIndex = 1;
			this->Confirm->Text = L"Confirm";
			this->Confirm->UseVisualStyleBackColor = false;
			this->Confirm->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 708);
			this->Controls->Add(this->Confirm);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::string str;
		str = this->note->getText();
		String^ str2 = gcnew String(str.c_str());
		this->textBox1->Text = str2;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string tmp = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		const char* s1 = tmp.c_str();
		this->note->setText(tmp);
		this->note->saveNote();
	}
	};
}
