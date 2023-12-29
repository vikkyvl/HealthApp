#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>
#include "ActivityPlans.h"
#include "Exercise.h"
#include "SortingStrategy.h"
#include "SortByName.h"
#include "SortByDate.h"

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
    bool askedForViewList = false;
    while (true)
    {
        if (!askedForViewList)
        {
            std::cout << "Do you want to view the list of existing plans? (yes/no): ";
            std::string viewListOption;
            std::getline(std::cin >> std::ws, viewListOption);

            if (viewListOption == "yes" || viewListOption == "Yes" || viewListOption == "YES")
            {
                displayExerciseList();
            }
            else if (viewListOption == "no" || viewListOption == "No" || viewListOption == "NO")
            {

            }
            else
            {
                std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";
                continue;
            }
            askedForViewList = true;
        }

        std::cout << "Enter exercise name: ";
        std::string newExerciseName;
        std::getline(std::cin >> std::ws, newExerciseName);

        std::cout << "Enter date (YYYY-MM-DD): ";
        std::string newDate;
        std::getline(std::cin >> std::ws, newDate);

        std::cout << "Enter start time (HH:MM AM/PM): ";
        std::string newStartTime;
        std::getline(std::cin >> std::ws, newStartTime);

        std::cout << "Enter duration (e.g., 30m, 1h, 45s): ";
        std::string newDuration;
        std::getline(std::cin >> std::ws, newDuration);

        setNameExercise(newExerciseName);
        setDate(newDate);
        setTimeStart(newStartTime);
        setDuration(newDuration);

        savePlanToFile();
        if (!askForAnotherActivity())
        {
            break;
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

void ActivityPlans::viewPastPlans() const
{
    std::cout << "Choose an option:\n"
        << "1. View entire list\n"
        << "2. View by date\n"
        << "3. View sorted list\n"
        << "Enter your choice (1/2/3): ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        displayEntireList();
        break;
    case 2:
        viewByDate();
        break;
    case 3:
        viewSortedPlans();
        break;
    default:
        std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
    }
}

void ActivityPlans::displayPlans(const std::vector<std::string>& plans) const
{
    for (const std::string& line : plans)
    {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string exerciseName, date, startTime, duration;

        iss >> exerciseName >> date;

        std::string token;
        while (iss >> token)
        {
            if (token.find("AM") != std::string::npos || token.find("PM") != std::string::npos)
            {
                startTime += " " + token;
                break;
            }
            startTime += " " + token;
        }

        std::getline(iss, duration);

        std::cout << "Exercise: " << exerciseName << "\n"
            << "Date: " << date << "\n"
            << "Start time:" << startTime << "\n"
            << "Duration:" << duration << "\n\n";
    }
}

void ActivityPlans::viewByDate() const
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the specific date (YYYY-MM-DD): ";
    std::string targetDate;
    std::getline(std::cin, targetDate);

    std::vector<std::string> plans = readPlansFromFile();

    std::vector<std::string> plansOnDate;
    for (const std::string& plan : plans)
    {
        std::istringstream iss(plan);
        std::string exercise, date, time, duration;
        iss >> exercise >> date >> time >> duration;

        if (date == targetDate)
        {
            plansOnDate.push_back(plan);
        }
    }

    if (!plansOnDate.empty())
    {
        std::cout << "Plans for date " << targetDate << ":" << std::endl;
        displayPlans(plansOnDate);
    }
    else
    {
        std::cout << "No plans found for date " << targetDate << "." << std::endl;
    }
}

void ActivityPlans::displayEntireList() const
{
    std::vector<std::string> plans = readPlansFromFile();

    if (!plans.empty())
    {
        std::cout << "Entire list of plans:" << std::endl;
        displayPlans(plans);
    }
    else
    {
        std::cout << "No plans found." << std::endl;
    }
}

void ActivityPlans::viewSortedPlans() const
{
    std::cout << "Choose a sorting option:\n"
        << "1. Sort by name\n"
        << "2. Sort by date\n"
        << "3. Sort by duration\n"
        << "Enter your choice (1/2/3): ";

    int sortingChoice;
    std::cin >> sortingChoice;

    switch (sortingChoice)
    {
    case 1:
        sortByName();
        break;
    case 2:
        sortByDate();
        break;
    default:
        std::cout << "Invalid choice. Please enter 1, or 2." << std::endl;
    }
}

void ActivityPlans::sortByName() const
{
    sortingStrategy = std::make_unique<SortByName>();
    std::vector<std::string> plans = readPlansFromFile();
    sortingStrategy->sort(plans);
    displaySortedPlans(plans);
}

void ActivityPlans::sortByDate() const
{
    sortingStrategy = std::make_unique<SortByDate>();
    std::vector<std::string> plans = readPlansFromFile();
    sortingStrategy->sort(plans);
    displaySortedPlans(plans);
}

void ActivityPlans::setSortingStrategy(std::unique_ptr<SortingStrategy> strategy)
{
    sortingStrategy = std::move(strategy);
}

std::vector<std::string> ActivityPlans::readPlansFromFile() const
{
    std::ifstream file(filename);
    std::vector<std::string> plans;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (!line.empty())
            {
                plans.push_back(line);
            }
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    return plans;
}

void ActivityPlans::displaySortedPlans(const std::vector<std::string>& plans) const
{
    for (const auto& plan : plans)
    {
        std::cout << plan << '\n';
    }
}
