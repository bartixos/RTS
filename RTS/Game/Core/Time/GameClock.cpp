#include "stdafx.h"
#include "GameClock.h"
#include "Date.h"
#include <SFML/Graphics.hpp>

void GameClock::SetDate(const Date & date)
{
	this->date->SetDate(date);
}

void GameClock::SetSpeedUp() noexcept
{
	switch (speed)
	{
	case ClockSpeed::Pause:
	{
		speed = ClockSpeed::First;
		break;
	}
	case ClockSpeed::First:
	{
		speed = ClockSpeed::Second;
		break;
	}
	case ClockSpeed::Second:
	{
		speed = ClockSpeed::Third;
		break;
	}
	case ClockSpeed::Third:
	{
		speed = ClockSpeed::Fourth;
		break;
	}
	case ClockSpeed::Fourth:
	{
		speed = ClockSpeed::Fifht;
		break;
	}
	case ClockSpeed::Fifht:
		break;
	default:
		break;
	}
}

void GameClock::SetSpeedDown() noexcept
{
	switch (speed)
	{
	case ClockSpeed::Pause:
	{
		break;
	}
	case ClockSpeed::First:
	{
		break;
	}
	case ClockSpeed::Second:
	{
		speed = ClockSpeed::First;
		break;
	}
	case ClockSpeed::Third:
	{
		speed = ClockSpeed::Second;
		break;
	}
	case ClockSpeed::Fourth:
	{
		speed = ClockSpeed::Third;
		break;
	}
	case ClockSpeed::Fifht:
	{
		speed = ClockSpeed::Fourth;
		break;
	}
	default:
		break;
	}
}

void GameClock::SetPause() noexcept
{
	if (speed != ClockSpeed::Pause)
	{
		speedBeforePause = speed;
		speed = ClockSpeed::Pause;
	}
	else if (speed == ClockSpeed::Pause)
	{
		speed = speedBeforePause;
	}
}

std::string GameClock::GetSpeedLvByString() noexcept
{
	switch (speed)
	{
	case ClockSpeed::Pause:
	{
		return std::move(std::string("Pause"));
	}
	case ClockSpeed::First:
	{
		return std::move(std::string("First"));
	}
	case ClockSpeed::Second:
	{
		return std::move(std::string("Second"));
	}
	case ClockSpeed::Third:
	{
		return std::move(std::string("Third"));
	}
	case ClockSpeed::Fourth:
	{
		return std::move(std::string("Fourth"));
	}
	case ClockSpeed::Fifht:
	{
		return std::move(std::string("Fifht"));
	}

	default:
		break;
	}
	return std::string();
}

void GameClock::Initialize()
{
	speed = ClockSpeed::First;
	speedBeforePause = speed;
	date = std::make_unique<Date>(1, 1, 1000);
	actualMonth = date->GetMonth();
	actualYear = date->GetYear();
	fontManger = &*FontManager::GetInstance();
	font = &* fontManger->LoadResouce("default", "Font.ttf");

	dateText = std::make_unique<sf::Text>();
	dateText->setFont(*font);
	dateText->setCharacterSize(12);
	dateText->setFillColor(sf::Color::White);
	dateText->setOutlineColor(sf::Color::Black);
	dateText->setOutlineThickness(2);
	dateText->setPosition(600.f, 10.f);
	dateText->setString(date->ToWithMonthsString());
}

void GameClock::Update(float delta)
{
	if (speed != ClockSpeed::Pause)
	{
		if (isNextDay == true)
		{
			isNextDay = false;
		}
		if (isNextMonth == true)
		{
			isNextMonth = false;
		}
		if (isNextYear == true)
		{
			isNextYear = false;
		}

		delay -= delta;
		if (delay <= 0)
		{
			NextDay();
			isNextDay = true;
			if (actualMonth != date->GetMonth())
			{
				actualMonth = date->GetMonth();
				isNextMonth = true;
			}
			if (actualYear != date->GetYear())
			{
				actualYear = date->GetYear();
				isNextYear = true;
			}
		}
	}
}

void GameClock::Draw(sf::RenderWindow & window)
{
	if (dateText)
	{
		window.draw(*dateText);
	}
}

void GameClock::NextDay()
{
	switch (speed)
	{
	case ClockSpeed::Pause:
		break;
	case ClockSpeed::First:
	{
		delay = speed1delay;
		Log("Next Day after 2 sec");
		break;
	}
	case ClockSpeed::Second:
	{
		delay = speed2delay;
		Log("Next Day after 1.5 sec");
		break;
	}
	case ClockSpeed::Third:
	{
		delay = speed3delay;
		Log("Next Day after 1 sec");
		break;
	}
	case ClockSpeed::Fourth:
	{
		delay = speed4delay;
		Log("Next Day after 0.5 sec");
		break;
	}
	case ClockSpeed::Fifht:
	{
		delay = speed5delay;
		Log("Next Day after 0.25 sec");
		break;
	}
	default:
	{
		delay = speed1delay;
		break;
	}
	}
	//todo: Add that after 30/31 day set day to 1 and change month
	date->UpdateDate(1);

	dateText->setString(date->ToWithMonthsString());
}