#pragma once
#include <string>

int enumerateDate(int year, int month, int day);
extern int error;

namespace DateDistance {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;





	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox4;











	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(416, 14);
			this->button1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 73);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(282, 17);
			this->checkBox1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(116, 27);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Inclusive";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(282, 58);
			this->checkBox2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(116, 27);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Inclusive";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 35));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(3, 111);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 52);
			this->label2->TabIndex = 10;
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(13, 62);
			this->textBox3->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(120, 25);
			this->textBox3->TabIndex = 5;
			this->textBox3->TabStop = false;
			this->textBox3->Text = L"Ending Date";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(13, 19);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(130, 25);
			this->textBox2->TabIndex = 4;
			this->textBox2->TabStop = false;
			this->textBox2->Text = L"Starting Date";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(152, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 32);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"01/01/1155";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(152, 55);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(120, 32);
			this->textBox4->TabIndex = 2;
			this->textBox4->Text = L"01/08/2017";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(575, 192);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"How Many Days Between\?";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int inclusive{ 0 };
	String ^ date_one = textBox1->Text;
	String ^ date_two = textBox4->Text;

	int day = Convert::ToInt32(date_one->Substring(0, 2));
	int month = Convert::ToInt32(date_one->Substring(3, 2));
	int year = Convert::ToInt32(date_one->Substring(6, 4));

	int day_end = Convert::ToInt32(date_two->Substring(0, 2));
	int month_end = Convert::ToInt32(date_two->Substring(3, 2));
	int year_end = Convert::ToInt32(date_two->Substring(6, 4));

	int dateEnumeration_begin = enumerateDate(year, month, day);
	int dateEnumeration_end = enumerateDate(year_end, month_end, day_end);

	if (!checkBox1->Checked)
	{
		inclusive--;
	}
	if (checkBox2->Checked)
	{
		inclusive++;
	}

	// set the calucated days text 
	if (dateEnumeration_begin == dateEnumeration_end)
	{
		this->label2->Text = "That's The Same Day";

	}
	else if (error == 1)
	{
		this->label2->Text = "Invalid Date";
		error = 0;
	}
	else if (error == 2)
	{
		this->label2->Text = "Too Early. Try 1155+";
		error = 0;
	}
	else if (error == 3)
	{
		this->label2->Text = "DD/MM/YYYY";
		error = 0;
	}
	else if (error == 4)
	{
		this->label2->Text = "30 Days has September...";
	}
	else if (abs(dateEnumeration_end - dateEnumeration_begin) + inclusive == 1)
	{
		this->label2->Text = Convert::ToString(abs(dateEnumeration_end - dateEnumeration_begin) + inclusive) + " day between";
	}
	else
	{
		this->label2->Text = Convert::ToString(abs(dateEnumeration_end - dateEnumeration_begin) + inclusive) + " days between";
	}

}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}

};
}
