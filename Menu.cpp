#include <iostream>
#include "Menu.h"
#include "Exercise.h"
#include "ActivityPlans.h"

void Menu::showMainMenu() const
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Exercises Information" << std::endl;
    std::cout << "2. Activity Plans" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void Menu::run()
{
    int choice = 0;
    while (true)
    {
        showMainMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            exerciseRun.loadInformationFromFile();
            break;
        case 2:
            activityPlansRun.inputAndSavePlan();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            exit(0);
        }

    }
}
