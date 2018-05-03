#pragma once
#include <string>
#include <vector>

class SongManager
{
	std::string name; //name of song /DISPLAY
	std::string path;

	int difficulty_level; //0 easy , 1 medium , 2 hard   USER-INPUT
	int seconds; //Seconds in the song    //RETRIEVED
	int samples; //number of samples   //RETRIEVED
	//int tempo; //replaced with intensity

	std::vector<double> intensity; //CALCULATED
	std::vector<double> all_amplitudes; //All amplitudes stored   //RETRIEVED
	std::vector<bool> spawn_check; //If the amplitude at this point is above the spawn threshold then spawn an enemy //CALCULATED

	//Calculate spawn threshold, also used as flavour text
	double average_amplitude; //CALCUALTED
	double highest_amplitude; //RETRIEVED
	double lowest_amplitude; //RETRIEVED

	//How high the threshold has to eb 
	double spawn_threshold; //90% - easy , 80% - medium , 70% hard

	SongManager();

	void calculate_average_amplitude();

	void add_amplitude_value(double input_amplitude);

};