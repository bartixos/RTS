#include "stdafx.h"
#include "GameClock.h"
#include "Date.h"
#include <SFML/Graphics.hpp>

void GameClock::SateDate(const Date & date)
{
	this->date->SetDate(date);
}

void GameClock::Initialize()
{
	speed = ClockSpeed::Fifht;
	date = std::make_unique<Date>(1, 1, 1000);
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
	delay -= delta;
	if (delay <= 0)
	{
		NextDay();
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
	date->SetDay(date->GetDay() + 1);
	dateText->setString(date->ToWithMonthsString());
}