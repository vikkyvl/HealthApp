#pragma once
#include <string>
#include <ostream>
#include <fstream>

class ActivityPlans
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
	/*void viewPastPlans() const;*/

private:
	const std::string& filename = "ActivityPlansList.txt";
	std::string nameExercise;
	std::string date;
	std::string timeStart;
	std::string duration;
};

