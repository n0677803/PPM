#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SongSelect
	/// </summary>
	public ref class SongSelect : public System::Windows::Forms::Form
	{
	public:
		enum class Difficulty { EASY, MEDIUM, HARD };
		Difficulty Player_Difficulty; // Health level etc
	private: System::Windows::Forms::Label^  lbl_easy;
	private: System::Windows::Forms::Label^  lbl_normal;
	private: System::Windows::Forms::Label^  lbl_hard;
	private: System::Windows::Forms::Button^  btn_SongPick;
	private: System::Windows::Forms::TextBox^  txt_CurrentSong;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  lbl_song_length;


	public:







			 Difficulty Song_Difficulty;


		SongSelect(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			Player_Difficulty = Difficulty::MEDIUM;
			btn_player_diff_medium->BackColor = System::Drawing::Color::Maroon;

			Song_Difficulty = Difficulty::MEDIUM;
			btn_song_diff_medium->BackColor = System::Drawing::Color::Maroon;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SongSelect()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::Label^  lb_difficulty;
	private: System::Windows::Forms::Button^  btn_song_diff_easy;

	private: System::Windows::Forms::Button^  btn_song_diff_hard;
	private: System::Windows::Forms::Button^  btn_player_diff_hard;

	private: System::Windows::Forms::Button^  btn_player_diff_medium;

	private: System::Windows::Forms::Button^  btn_player_diff_easy;
	private: System::Windows::Forms::Button^  btn_song_diff_medium;




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
			this->lb_difficulty = (gcnew System::Windows::Forms::Label());
			this->btn_song_diff_easy = (gcnew System::Windows::Forms::Button());
			this->btn_song_diff_hard = (gcnew System::Windows::Forms::Button());
			this->btn_player_diff_hard = (gcnew System::Windows::Forms::Button());
			this->btn_player_diff_medium = (gcnew System::Windows::Forms::Button());
			this->btn_player_diff_easy = (gcnew System::Windows::Forms::Button());
			this->btn_song_diff_medium = (gcnew System::Windows::Forms::Button());
			this->lbl_easy = (gcnew System::Windows::Forms::Label());
			this->lbl_normal = (gcnew System::Windows::Forms::Label());
			this->lbl_hard = (gcnew System::Windows::Forms::Label());
			this->btn_SongPick = (gcnew System::Windows::Forms::Button());
			this->txt_CurrentSong = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lbl_song_length = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lb_difficulty
			// 
			this->lb_difficulty->AutoSize = true;
			this->lb_difficulty->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_difficulty->Location = System::Drawing::Point(66, 291);
			this->lb_difficulty->Name = L"lb_difficulty";
			this->lb_difficulty->Size = System::Drawing::Size(480, 44);
			this->lb_difficulty->TabIndex = 1;
			this->lb_difficulty->Text = L"PICK YOUR DIFFICULTY";
			// 
			// btn_song_diff_easy
			// 
			this->btn_song_diff_easy->BackColor = System::Drawing::Color::Aqua;
			this->btn_song_diff_easy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_song_diff_easy->ForeColor = System::Drawing::Color::Teal;
			this->btn_song_diff_easy->Location = System::Drawing::Point(105, 388);
			this->btn_song_diff_easy->Name = L"btn_song_diff_easy";
			this->btn_song_diff_easy->Size = System::Drawing::Size(80, 80);
			this->btn_song_diff_easy->TabIndex = 2;
			this->btn_song_diff_easy->UseVisualStyleBackColor = false;
			this->btn_song_diff_easy->Click += gcnew System::EventHandler(this, &SongSelect::btn_song_diff_easy_Click);
			// 
			// btn_song_diff_hard
			// 
			this->btn_song_diff_hard->BackColor = System::Drawing::Color::Aqua;
			this->btn_song_diff_hard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_song_diff_hard->ForeColor = System::Drawing::Color::Teal;
			this->btn_song_diff_hard->Location = System::Drawing::Point(393, 388);
			this->btn_song_diff_hard->Name = L"btn_song_diff_hard";
			this->btn_song_diff_hard->Size = System::Drawing::Size(80, 80);
			this->btn_song_diff_hard->TabIndex = 4;
			this->btn_song_diff_hard->UseVisualStyleBackColor = false;
			this->btn_song_diff_hard->Click += gcnew System::EventHandler(this, &SongSelect::btn_song_diff_hard_Click);
			// 
			// btn_player_diff_hard
			// 
			this->btn_player_diff_hard->BackColor = System::Drawing::Color::Aqua;
			this->btn_player_diff_hard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_player_diff_hard->ForeColor = System::Drawing::Color::Teal;
			this->btn_player_diff_hard->Location = System::Drawing::Point(393, 484);
			this->btn_player_diff_hard->Name = L"btn_player_diff_hard";
			this->btn_player_diff_hard->Size = System::Drawing::Size(80, 80);
			this->btn_player_diff_hard->TabIndex = 7;
			this->btn_player_diff_hard->UseVisualStyleBackColor = false;
			this->btn_player_diff_hard->Click += gcnew System::EventHandler(this, &SongSelect::btn_player_diff_hard_Click);
			// 
			// btn_player_diff_medium
			// 
			this->btn_player_diff_medium->BackColor = System::Drawing::Color::Aqua;
			this->btn_player_diff_medium->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_player_diff_medium->ForeColor = System::Drawing::Color::Teal;
			this->btn_player_diff_medium->Location = System::Drawing::Point(251, 484);
			this->btn_player_diff_medium->Name = L"btn_player_diff_medium";
			this->btn_player_diff_medium->Size = System::Drawing::Size(80, 80);
			this->btn_player_diff_medium->TabIndex = 6;
			this->btn_player_diff_medium->UseVisualStyleBackColor = false;
			this->btn_player_diff_medium->Click += gcnew System::EventHandler(this, &SongSelect::btn_player_diff_medium_Click);
			// 
			// btn_player_diff_easy
			// 
			this->btn_player_diff_easy->BackColor = System::Drawing::Color::Aqua;
			this->btn_player_diff_easy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_player_diff_easy->ForeColor = System::Drawing::Color::Teal;
			this->btn_player_diff_easy->Location = System::Drawing::Point(105, 484);
			this->btn_player_diff_easy->Name = L"btn_player_diff_easy";
			this->btn_player_diff_easy->Size = System::Drawing::Size(80, 80);
			this->btn_player_diff_easy->TabIndex = 5;
			this->btn_player_diff_easy->UseVisualStyleBackColor = false;
			this->btn_player_diff_easy->Click += gcnew System::EventHandler(this, &SongSelect::btn_player_diff_easy_Click);
			// 
			// btn_song_diff_medium
			// 
			this->btn_song_diff_medium->BackColor = System::Drawing::Color::Aqua;
			this->btn_song_diff_medium->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_song_diff_medium->ForeColor = System::Drawing::Color::Teal;
			this->btn_song_diff_medium->Location = System::Drawing::Point(251, 388);
			this->btn_song_diff_medium->Name = L"btn_song_diff_medium";
			this->btn_song_diff_medium->Size = System::Drawing::Size(80, 80);
			this->btn_song_diff_medium->TabIndex = 8;
			this->btn_song_diff_medium->UseVisualStyleBackColor = false;
			this->btn_song_diff_medium->Click += gcnew System::EventHandler(this, &SongSelect::bn_song_diff_medium_Click);
			// 
			// lbl_easy
			// 
			this->lbl_easy->AutoSize = true;
			this->lbl_easy->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_easy->Location = System::Drawing::Point(98, 346);
			this->lbl_easy->Name = L"lbl_easy";
			this->lbl_easy->Size = System::Drawing::Size(107, 39);
			this->lbl_easy->TabIndex = 9;
			this->lbl_easy->Text = L"EASY";
			// 
			// lbl_normal
			// 
			this->lbl_normal->AutoSize = true;
			this->lbl_normal->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_normal->Location = System::Drawing::Point(211, 346);
			this->lbl_normal->Name = L"lbl_normal";
			this->lbl_normal->Size = System::Drawing::Size(162, 39);
			this->lbl_normal->TabIndex = 10;
			this->lbl_normal->Text = L"NORMAL";
			// 
			// lbl_hard
			// 
			this->lbl_hard->AutoSize = true;
			this->lbl_hard->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hard->Location = System::Drawing::Point(379, 346);
			this->lbl_hard->Name = L"lbl_hard";
			this->lbl_hard->Size = System::Drawing::Size(118, 39);
			this->lbl_hard->TabIndex = 11;
			this->lbl_hard->Text = L"HARD";
			// 
			// btn_SongPick
			// 
			this->btn_SongPick->BackColor = System::Drawing::Color::Aqua;
			this->btn_SongPick->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_SongPick->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_SongPick->ForeColor = System::Drawing::Color::Maroon;
			this->btn_SongPick->Location = System::Drawing::Point(20, 61);
			this->btn_SongPick->Name = L"btn_SongPick";
			this->btn_SongPick->Size = System::Drawing::Size(526, 70);
			this->btn_SongPick->TabIndex = 12;
			this->btn_SongPick->Text = L"PICK A SONG";
			this->btn_SongPick->UseVisualStyleBackColor = false;
			this->btn_SongPick->Click += gcnew System::EventHandler(this, &SongSelect::btn_SongPick_Click);
			// 
			// txt_CurrentSong
			// 
			this->txt_CurrentSong->Location = System::Drawing::Point(20, 153);
			this->txt_CurrentSong->Name = L"txt_CurrentSong";
			this->txt_CurrentSong->ReadOnly = true;
			this->txt_CurrentSong->Size = System::Drawing::Size(526, 20);
			this->txt_CurrentSong->TabIndex = 13;
			this->txt_CurrentSong->Text = L"-Select a song-";
			this->txt_CurrentSong->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Aqua;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Maroon;
			this->button1->Location = System::Drawing::Point(726, 536);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(526, 133);
			this->button1->TabIndex = 14;
			this->button1->Text = L"PLAY";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"MP3|*.mp3";
			this->openFileDialog1->InitialDirectory = L"C:\\";
			this->openFileDialog1->Title = L"Import a song";
			// 
			// lbl_song_length
			// 
			this->lbl_song_length->AutoSize = true;
			this->lbl_song_length->Location = System::Drawing::Point(248, 185);
			this->lbl_song_length->Name = L"lbl_song_length";
			this->lbl_song_length->Size = System::Drawing::Size(78, 13);
			this->lbl_song_length->TabIndex = 15;
			this->lbl_song_length->Text = L"-Select a song-";
			// 
			// SongSelect
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->lbl_song_length);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txt_CurrentSong);
			this->Controls->Add(this->btn_SongPick);
			this->Controls->Add(this->lbl_hard);
			this->Controls->Add(this->lbl_normal);
			this->Controls->Add(this->lbl_easy);
			this->Controls->Add(this->btn_song_diff_medium);
			this->Controls->Add(this->btn_player_diff_hard);
			this->Controls->Add(this->btn_player_diff_medium);
			this->Controls->Add(this->btn_player_diff_easy);
			this->Controls->Add(this->btn_song_diff_hard);
			this->Controls->Add(this->btn_song_diff_easy);
			this->Controls->Add(this->lb_difficulty);
			this->Name = L"SongSelect";
			this->Text = L"SongSelect";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_song_diff_easy_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua, 1);
		this->btn_song_diff_easy->BackColor = System::Drawing::Color::Maroon;
		Song_Difficulty = Difficulty::EASY;
	}//end song diff easy

	private: System::Void bn_song_diff_medium_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua , 1);
		this->btn_song_diff_medium->BackColor = System::Drawing::Color::Maroon;
		Song_Difficulty = Difficulty::EASY;
	}//end song diff medium

	private: System::Void btn_song_diff_hard_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua , 1);
		this->btn_song_diff_hard->BackColor = System::Drawing::Color::Maroon;
		Song_Difficulty = Difficulty::HARD;
	}//end song diff hard

	private: System::Void btn_player_diff_easy_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua , 2);
		this->btn_player_diff_easy->BackColor = System::Drawing::Color::Maroon;
		Player_Difficulty = Difficulty::EASY;
	}//end player diff easy

	private: System::Void btn_player_diff_medium_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua , 2);
		this->btn_player_diff_medium->BackColor = System::Drawing::Color::Maroon;
		Player_Difficulty = Difficulty::MEDIUM;
	}//end player diff medium

	private: System::Void btn_player_diff_hard_Click(System::Object^  sender, System::EventArgs^  e) {
		reset_button_colors(System::Drawing::Color::Aqua , 2);
		this->btn_player_diff_hard->BackColor = System::Drawing::Color::Maroon;
		Player_Difficulty = Difficulty::HARD;
	}//end player diff hard

	
	void reset_button_colors(Color input_color , int row);

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


}
private: System::Void btn_SongPick_Click(System::Object^  sender, System::EventArgs^  e) {

	this->openFileDialog1->FileName = "";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		this->txt_CurrentSong->Clear();//Clears the textbox
		this->txt_CurrentSong->Text = openFileDialog1->FileName;//Retrieves the path of the file
		//this->lbl_song_length->Text = openFileDialog1->

		//Return mp3 length
		//Get the total frames of the mp3 file, and then convert that to SS::MM:HH 
		//https://stackoverflow.com/questions/23776115/get-mp3-length-in-c


	}

}
};


}
