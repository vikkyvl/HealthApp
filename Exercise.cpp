#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Exercise.h"

Exercise::Exercise() {}

Exercise::~Exercise()
{
	clear();
}

void Exercise::loadInformationFromFile()
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		while (std::getline(file, exerciseName))
		{
			exerciseData.push_back(exerciseName);
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
}

void Exercise::displayExerciseList()
{
	if(exerciseData.empty())
	{ 
		loadInformationFromFile();
	}
	printExerciseData();
}

void Exercise::addNewActivity()
{
	do
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Enter new activity (separate multiple activities by spaces): ";
		std::string input;
		std::getline(std::cin, input);

		std::ofstream file(filename, std::ios::app);

		if (file.is_open())
		{
			file << input << '\n';

			file.close();
			std::cout << "Data successfully added to the file." << std::endl;
		}
		else
		{
			std::cout << "Unable to open file for appending" << std::endl;
			exit(1);
		}

	} while (askForAnotherActivity());
}

bool Exercise::askForAnotherActivity()
{
	while (true)
	{
		std::cout << "Do you want to enter another activity? (yes/no): ";
		std::string anotherActivity;
		std::cin >> anotherActivity;

		if (anotherActivity == "yes")
		{
			return true;
		}
		else if (anotherActivity == "no")
		{
			return false;
		}
		else
		{
			std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
		}
	}
}

void Exercise::sortInformation()
{
	if (exerciseData.empty())
	{
		loadInformationFromFile();
	}
	std::sort(exerciseData.begin(), exerciseData.end());
	std::cout << "Sorted Data:" << std::endl;
	printExerciseData();
}

void Exercise::printExerciseData() const
{
	for (const std::string& data : exerciseData)
	{
		std::cout << data << std::endl;
	}
}

void Exercise::deleteExercise()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (exerciseData.empty())
	{
		loadInformationFromFile();
	}

	std::cout << "Enter the name of the exercise to delete: ";
	std::string exerciseName;
	std::getline(std::cin, exerciseName);

	auto it = std::find(exerciseData.begin(), exerciseData.end(), exerciseName);

	if (it != exerciseData.end())
	{
		exerciseData.erase(it);

		updateFile();
		std::cout << "Exercise '" << exerciseName << "' successfully deleted." << std::endl;
	}
	else
	{
		std::cout << "Exercise '" << exerciseName << "' not found." << std::endl;
	}
}

void Exercise::updateFile()
{
	std::ofstream file(filename, std::ios::trunc);

	if (file.is_open())
	{
		for (const std::string& data : exerciseData)
		{
			file << data << '\n';
		}

		file.close();
	}
	else
	{
		throw std::runtime_error("Unable to open file for updating");
	}
}

void Exercise::clear()
{
	exerciseData.clear();
}
