#include <iostream>
#include "ActivityPlans.h"

ActivityPlans::ActivityPlans() {}

ActivityPlans::ActivityPlans(const std::string& nameExercise, const std::string& date, const std::string& timeStart, const std::string& duration) : nameExercise(nameExercise), date(date), timeStart(timeStart), duration(duration){}

ActivityPlans::~ActivityPlans(){}

std::string ActivityPlans::getNameExercise() const
{
    return nameExercise;
}

std::string ActivityPlans::getDate() const
{
    return date;
}

std::string ActivityPlans::getTimeStart() const
{
    return timeStart;
}

std::string ActivityPlans::getDuration() const
{
    return duration;
}

void ActivityPlans::setNameExercise(const std::string& newNameExercise)
{
    nameExercise = newNameExercise;
}

void ActivityPlans::setDate(const std::string& newDate)
{
    date = newDate;
}

void ActivityPlans::setTimeStart(const std::string& newTimeStart)
{
    timeStart = newTimeStart;
}

void ActivityPlans::setDuration(const std::string& newDuration)
{
    duration = newDuration;
}

void ActivityPlans::inputAndSavePlan()
{
    while (true)
    {
        std::cout << "Enter exercise name: ";
        std::string newExerciseName;
        std::cin >> newExerciseName;

        std::cout << "Enter date (YYYY-MM-DD): ";
        std::string newDate;
        std::cin >> newDate;

        std::cout << "Enter start time (HH:MM AM/PM): ";
        std::string newStartTime;
        std::cin >> newStartTime;

        std::cout << "Enter duration: ";
        std::string newDuration;
        std::cin >> newDuration;

        setNameExercise(newExerciseName);
        setDate(newDate);
        setTimeStart(newStartTime);
        setDuration(newDuration);

        savePlanToFile();

        while (true) {

            std::cout << "Do you want to enter another activity? (yes/no): ";
            std::string anotherActivity;
            std::cin >> anotherActivity;

            if (anotherActivity == "yes") 
            {
                break; 
            }
            else if (anotherActivity == "no") 
            {
                return; 
            }
            else 
            {
                std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
            }
        }
    }
}

void ActivityPlans::savePlanToFile() const
{
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) 
    {
        file << getNameExercise() << ' ' << getDate() << ' ' << getTimeStart() << ' ' << getDuration() << '\n';
        file.close();
    }
    else 
    {
        std::cout << "Unable to open file" << std::endl;
        exit(1);
    }
}
