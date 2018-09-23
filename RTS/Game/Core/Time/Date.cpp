#include "stdafx.h"
#include "Date.h"

Date::Date() :
	day(0),
	month(0),
	year(0)
{
}

Date::Date(int day, int month, int year) :
	day(day),
	month(month),
	year(year)
{
}

Date::Date(const Date & date) :
	day(date.day),
	month(date.month),
	year(date.year)
{
}

Date::Date(Date && date) :
	day(std::move(date.day)),
	month(std::move(date.month)),
	year(std::move(date.year))
{
}

void Date::SetDate(int day, int month, int year)
{
	if (day >= 1 && day <= 31 && month >= 1 && month <= 12)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

void Date::SetDate(const Date & date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

std::string Date::GetMonthByString()
{
	std::string result;
	if (month >= 1 && month <= 12)
	{
		switch (month)
		{
		case 1:
		{
			result = "January";
			break;
		}
		case 2:
		{
			result = "February";
			break;
		}
		case 3:
		{
			result = "March";
			break;
		}
		case 4:
		{
			result = "April";
			break;
		}
		case 5:
		{
			result = "May";
			break;
		}
		case 6:
		{
			result = "June";
			break;
		}
		case 7:
		{
			result = "July";
			break;
		}
		case 8:
		{
			result = "August";
			break;
		case 9:
		{
			result = "September";
			break;
		}
		case 10:
		{
			result = "October";
			break;
		}
		case 11:
		{
			result = "November";
			break;
		}
		case 12:
		{
			result = "December";
			break;
		}
		}
		default:
			break;
		}
	}

	else
	{
		Log("Month is Too High or too low");
	}
	return std::move(result);
}

std::string Date::ToString()
{
	return std::move(std::string(std::to_string(day) + " - " + std::to_string(month) + " - " + std::to_string(year)));
}

std::string Date::ToWithMonthsString()
{
	return std::move(std::string(std::to_string(day) + " - " + GetMonthByString() + " - " + std::to_string(year)));
}