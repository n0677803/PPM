#pragma once
#include "SongSelect.h"
namespace Project {

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
	private: System::Windows::Forms::Button^  btn_play;
	private: System::Windows::Forms::Button^  btn_help;
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::PictureBox^  pic_Background;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_help = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->pic_Background = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_Background))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_play
			// 
			this->btn_play->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_play->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_play->Location = System::Drawing::Point(12, 357);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(300, 100);
			this->btn_play->TabIndex = 0;
			this->btn_play->Text = L"PLAY";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::btn_play_Click);
			// 
			// btn_help
			// 
			this->btn_help->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_help->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_help->Location = System::Drawing::Point(12, 463);
			this->btn_help->Name = L"btn_help";
			this->btn_help->Size = System::Drawing::Size(300, 100);
			this->btn_help->TabIndex = 1;
			this->btn_help->Text = L"HELP";
			this->btn_help->UseVisualStyleBackColor = true;
			// 
			// btn_exit
			// 
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_exit->Location = System::Drawing::Point(12, 569);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(300, 100);
			this->btn_exit->TabIndex = 2;
			this->btn_exit->Text = L"EXIT";
			this->btn_exit->UseVisualStyleBackColor = true;
			// 
			// pic_Background
			// 
			this->pic_Background->Location = System::Drawing::Point(-11, -2);
			this->pic_Background->Name = L"pic_Background";
			this->pic_Background->Size = System::Drawing::Size(1280, 720);
			this->pic_Background->TabIndex = 3;
			this->pic_Background->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_help);
			this->Controls->Add(this->btn_play);
			this->Controls->Add(this->pic_Background);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_Background))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_play_Click(System::Object^  sender, System::EventArgs^  e) {

			SongSelect ^ SongSelectionForm = gcnew SongSelect; //Create new instance of the form
			this->Visible = false; //Hide this form
			SongSelectionForm->ShowDialog();

	}//end button play click
};

void Open_Selection();

}
