#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include "Exercise.h"
#include "SortingStrategy.h"
#include "SortByName.h"
#include "SortByDate.h"

class ActivityPlans : public Exercise
{
public:
	ActivityPlans();
	ActivityPlans(const std::string& nameExercise, const std::string& date, const std::string& timeStart, const std::string& duration);
	~ActivityPlans();
	std::string getNameExercise() const;
	std::string getDate() const;
	std::string getTimeStart() const;
	std::string getDuration() const;

	void setNameExercise(const std::string& newNameExercise);
	void setDate(const std::string& newDate);
	void setTimeStart(const std::string& newTimeStart);
	void setDuration(const std::string& newDuration);

	void inputAndSavePlan();
	void savePlanToFile() const;
	void viewPastPlans() const;

	void displayPlans(const std::vector<std::string>& plans) const;
	void displayEntireList() const;
	void viewByDate() const;
	void viewSortedPlans() const;
	void sortByDate() const;
	void sortByName() const;
	void setSortingStrategy(std::unique_ptr<SortingStrategy> strategy);
	std::vector<std::string> readPlansFromFile() const;
	void displaySortedPlans(const std::vector<std::string>& plans) const;
private:
	const std::string& filename = "ActivityPlansList.txt";
	std::string nameExercise;
	std::string date;
	std::string timeStart;
	std::string duration;
	std::unique_ptr<SortingStrategy> sortingStrategy;
};

