#include <iostream>
#include "Menu.h"
#include "PhysicalActivityBase.h"

void Menu::showMainMenu() const
{
    std::cout << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. See my exercise sheet" << std::endl;
    std::cout << "2. Create activity plans" << std::endl;
    std::cout << "3. Sort activity plans" << std::endl;
    std::cout << "4. Add new activity" << std::endl;
    std::cout << "5. View past plans" << std::endl;
    std::cout << "6. Delete my exercise" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::endl;
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
            physicalActivityBaseMenu.displayExerciseList();
            break;
        case 2:
            physicalActivityBaseMenu.inputAndSavePlan();
            break;
        case 3:
            physicalActivityBaseMenu.sortInformation();
            break;
        case 4:
            physicalActivityBaseMenu.addNewActivity();
            break;
        case 5: 
            physicalActivityBaseMenu.viewPastPlans();
            break;
        case 6:
            physicalActivityBaseMenu.deleteExercise();
            break;        
        case 7:
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

    }
}
