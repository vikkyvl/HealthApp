#pragma once
#include "Exercise.h"
#include "ActivityPlans.h"

class Menu
{
public:
	void showMainMenu() const;
	void run();

	Exercise exerciseRun;
	ActivityPlans activityPlansRun;
};

