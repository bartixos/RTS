#pragma once
#include "cereal/cereal.hpp"
#include "cereal/access.hpp"
class Date
{
private:
	friend cereal::access;
	int day;
	int month;
	int year;
public:

	template<typename Archive>
	void save(Archive& archive) const
	{
		archive(CEREAL_NVP_("day", day), CEREAL_NVP_("month", month), CEREAL_NVP_("year", year));
	}
	template<typename Archive>
	void Load(Archive& archive)
	{
		archive(CEREAL_NVP_("day", day), CEREAL_NVP_("month", month), CEREAL_NVP_("year", year));
	}

	Date();
	Date(int day = 0, int month = 0, int year = 0);
	Date(const Date& date);
	Date(Date&& date);

	void SetDate(int day, int month, int year);
	void SetDate(const Date& date);
	static bool IsEqual(const Date& date1, const Date& date2) noexcept;

	int GetDay() noexcept
	{
		return day;
	}
	int GetMonth() noexcept
	{
		return month;
	}
	int GetYear() noexcept
	{
		return year;
	}

	void SetDay(int _day) noexcept
	{
		day = _day;
	}
	void SetMonth(int _month) noexcept
	{
		month = _month;
	}
	void SetYear(int _year) noexcept
	{
		year = _year;
	}

	std::string GetMonthByString();

	bool operator == (const Date& date)
	{
		if (day == date.day && month == date.month && year == date.year)
		{
			return true;
		}
		else
			return false;
	}

	friend bool operator == (const Date& date, const Date& date2)
	{
		if (date2.day == date.day && date2.month == date.month && date2.year == date.year)
		{
			return true;
		}
		else
			return false;
	}

	bool operator != (const Date& date)
	{
		if (*this == date)
		{
			return false;
		}
		else
			return true;
	}

	friend bool operator != (const Date& date, const Date& date2)
	{
		if (date2 == date)
		{
			return false;
		}
		else
			return true;
	}

	std::string ToString();
	std::string ToWithMonthsString();
};
