#pragma once
#include <vector>
#include <string>

class Exercise
{
public:
	Exercise();
	~Exercise();

	void loadInformationFromFile();
	void clear();

	/*void addNewActivity();*/
	/*void sortInformation();*/
private:
	const std::string& filename = "ExerciseList.txt";
	std::string exerciseName;
	std::vector<std::string> exerciseData;
};

