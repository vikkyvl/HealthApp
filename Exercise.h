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
	void displayExerciseList();
	void addNewActivity();
	void sortInformation();
	void printExerciseData() const;
	void deleteExercise();
	void updateFile();
	bool askForAnotherActivity();
	void askForDisplayExerciseList();
private:
	const std::string& filename = "ExerciseList.txt";
	std::string exerciseName;
	std::vector<std::string> exerciseData;
};

