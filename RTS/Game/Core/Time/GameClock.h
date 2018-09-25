#pragma once

#include "Utility/ASingleton.h"
#include "Core/ResourcesManager/FontManager.h"

namespace sf
{
	class Font;
	class Text;
	class RenderWindow;
}

class Date;

enum class ClockSpeed
{
	Pause,
	First,
	Second,
	Third,
	Fourth,
	Fifht
};

class GameClock : public ASingleton<GameClock>
{
	UniquePtr<Date> date;
	sf::Font * font;
	UniquePtr<sf::Text> dateText;
	ClockSpeed speed;
	ClockSpeed speedBeforePause;
	FontManager * fontManger;
	static inline bool isNextDay = false;
	static inline bool isNextMonth = false;
	static inline bool isNextYear = false;

	int actualMonth = 0;
	int actualYear = 0;
	const float speed1delay = 2.f, speed2delay = 1.5f, speed3delay = 1.f, speed4delay = 0.5f, speed5delay = .25f;
	float delay;

	void NextDay();
public:
	void SetDate(const Date& date);
	void SetSpeedUp() noexcept;
	void SetSpeedDown() noexcept;
	void SetPause() noexcept;
	std::string GetSpeedLvByString() noexcept;
	ClockSpeed GetClockSpeed() const noexcept { return speed; }
	const Date& GetDate() const noexcept
	{
		return *date;
	}
	void Initialize();
	void Update(float delta);
	void Draw(sf::RenderWindow &window);
};