#include "SongSelect.h"

using namespace System; //Provides functions to work with UI controls
using namespace System::Windows::Forms;
//http://www.bogotobogo.com/cplusplus/application_visual_studio_2013.php

//Namespace , form class , function name
namespace Project {
	void SongSelect::reset_button_colors(Color input_color, int row)
	{
		//Reset all their colors to base
		//Top row
		if (row == 1)
		{
			btn_song_diff_easy->BackColor = input_color;
			btn_song_diff_medium->BackColor = input_color;
			btn_song_diff_hard->BackColor = input_color;
		}
		else if (row == 2)
		{		
			btn_player_diff_easy->BackColor = input_color;
			btn_player_diff_medium->BackColor = input_color;
			btn_player_diff_hard->BackColor = input_color;
		}


	}
}