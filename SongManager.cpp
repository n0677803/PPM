#include "SongManager.h"

SongManager::SongManager()
{
	name = "";
	path = "";
	difficulty_level = 0;
	seconds = 0;
	samples = 0;

	average_amplitude = 0;
	highest_amplitude = 0;
	lowest_amplitude = 10000; //0 already lowest value

	spawn_threshold = 0;

}

void SongManager :: calculate_average_amplitude()
{
	double gross_amplitude;


	for (int i = 0; i < all_amplitudes.size(); i++)
	{
		gross_amplitude += all_amplitudes[i];
	}

	average_amplitude = gross_amplitude / all_amplitudes.size();

}

void SongManager ::add_amplitude_value(double input_amplitude)
{
	if (input_amplitude > highest_amplitude)
		highest_amplitude = input_amplitude;
	else if (input_amplitude < lowest_amplitude)
		lowest_amplitude = input_amplitude;


	all_amplitudes.push_back(input_amplitude);


}