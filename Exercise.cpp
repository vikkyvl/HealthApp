#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Exercise.h"

Exercise::Exercise()
{
	/*std::cout << "Exercise created" << std::endl;*/
}

Exercise::~Exercise()
{
	clear();
	/*std::cout << "Exercise destroyed" << std::endl;*/
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

//void Exercise::addNewActivity()
//{
//	//Введення нових даних користувачем
//}

//void Exercise::sortInformation()
//{
//
//}

void Exercise::clear()
{
	exerciseData.clear();
}
