#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

void PrintCalendar(string days, string month, int year);

void PrintLines(string days);

std::string Caps(string month);

int NumDays(string month);

bool ValidMonth(string month);

int WeekdayNum(string month, int year);

std::string DaysString(int num_days, int weekday);

int GetValidYear();

#endif