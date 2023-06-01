#pragma once

namespace LAB78 {
	class Data {
	public:
		int day;
		int month;
		int year;

		// Конструктор класу Data
		Data(int d, int m, int y) : day(d), month(m), year(y) {}

		// Метод для порівняння двох дат
		// Повертає true, якщо поточна дата більша за іншу дату
		bool isLaterThan(Data other) {
			if (year > other.year)
				return true;
			else if (year < other.year)
				return false;
			else {
				if (month > other.month)
					return true;
				else if (month < other.month)
					return false;
				else {
					if (day > other.day)
						return true;
					else
						return false;
				}
			}
		}
	};
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(193, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Визначення пізнішої дати";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(250, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Визначити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(92, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Перша дата";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(484, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Друга дата";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(292, 252);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 16);
			this->label4->TabIndex = 6;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(54, 155);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(185, 22);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(420, 155);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(206, 22);
			this->textBox2->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(228, 281);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(189, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Тут з\'явиться результат";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(487, 332);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 52);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Очистити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(159, 66);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(360, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Введіть дати в такому форматі ДД/ММ/РРРР";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(661, 414);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторна 7-8";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ data1 = this->textBox1->Text;
		String^ data2 = this->textBox2->Text;
		// Розбиваємо рядок на день, місяць і рік
		array<String^>^ parts1 = data1->Split('/');
		array<String^>^ parts2 = data2->Split('/');

		// Перевіряємо кількість елементів у розбитому рядку
		if (parts1->Length != 3) {
			throw gcnew System::Exception("Некоректний формат першої дати.");
		}
		if (parts2->Length != 3) {
			throw gcnew System::Exception("Некоректний формат другої дати.");
		}

		// Перевіряємо символи в рядку
		if (!isValidCharacters(parts1) || !isValidCharacters(parts2)) {
			throw gcnew System::Exception("Некоректний формат дати.");
		}

		// Перетворюємо рядки у цілі числа
		int day1 = Int32::Parse(parts1[0]);
		int month1 = Int32::Parse(parts1[1]);
		int year1 = Int32::Parse(parts1[2]);

		int day2 = Int32::Parse(parts2[0]);
		int month2 = Int32::Parse(parts2[1]);
		int year2 = Int32::Parse(parts2[2]);

		// Перевіряємо коректність дати
		if (!isValidDate(day1, month1, year1)) {
			throw gcnew System::Exception("Некоректна перша дата.");
		}
		if (!isValidDate(day2, month2, year2)) {
			throw gcnew System::Exception("Некоректна друга дата.");
		}

		// Створюємо об'єкти класу Data
		Data date1(day1, month1, year1);
		Data date2(day2, month2, year2);

		// Порівнюємо дати
		if (date1.isLaterThan(date2)) {
			this->label5->Text = "Пізніша дата: " + data1;
		}
		else if (date2.isLaterThan(date1)) {
			this->label5->Text = "Пізніша дата: " + data2;
		}
		else  {
			this->label5->Text = "Дати однакові";
		}
	}
	catch (System::Exception^ ex) {
		this->label5->Text = ex->Message;
		if (ex->Message->Contains("перша")) {
			this->textBox1->Text = "";
		}
		else if (ex->Message->Contains("друга")) {
			this->textBox2->Text = "";
		}
		else if (ex->Message->Contains("Некоректний формат першої дати.")) {
			this->textBox1->Text = "";
		}
		else if (ex->Message->Contains("Некоректний формат другої дати.")) {
			this->textBox2->Text = "";
		}
		
	}
}

	   // Перевіряє символи в рядку
	   bool isValidCharacters(array<String^>^ parts) {
		   for each (String ^ part in parts) {
			   for each (Char c in part) {
				   if (!Char::IsDigit(c) && c != '/') {
					   return false;
				   }
			   }
		   }
		   return true;
	   }



	   // Перевіряє коректність дати
	   bool isValidDate(int day, int month, int year) {
		   if (year < 0 || month < 1 || month > 12 || day < 1)
			   return false;

		   int daysInMonth = getDaysInMonth(month, year);
		   return day <= daysInMonth;
	   }

	   // Отримує кількість днів у місяці
	   int getDaysInMonth(int month, int year) {
		   if (month == 2) {
			   if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				   return 29;
			   else
				   return 28;
		   }
		   else if (month == 4 || month == 6 || month == 9 || month == 11) {
			   return 30;
		   }
		   else {
			   return 31;
		   }
	   }
	 private:
		 System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			 this->textBox1->Text = ""; // Очищаємо textBox1
			 this->textBox2->Text = ""; // Очищаємо textBox2
			 this->label5->Text = "Тут з'явиться результат" ;
		 }

};

}


