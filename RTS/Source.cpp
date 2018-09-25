#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/ResourcesManager/TextureManager.h"
#include "Utility/FpsCounter.h"
#include "Core/GameTimer.h"
#include "Game/Core/Time/Date.h"
#include "Game/Core/Time/GameClock.h"
int main()
{
	/*{
		std::ofstream save("save.txt");
		cereal::BinaryOutputArchive archive(save);
		std::vector<int> intarray = { 1,2,5,6,8,2,4,6 };
		archive(CEREAL_NVP(intarray));
		save.close();
	}

	{
		std::ifstream load("save.txt");
		cereal::BinaryInputArchive archive(load);
		std::vector<int> intarray;
		archive(intarray);
		for (auto lib : intarray)
		{
			std::cout << lib << "\n";
		}
		load.close();
	}*/

	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(800, 600), "Random Title");

	sf::Event event;

	auto fpsCounter = FpsCounter::GetInstance();
	fpsCounter->Initialize();

	auto texManager = TextureManager::GetInstance();

	auto gameTimer = GameTimer::GetInstance();

	sf::Texture *tex = &*texManager->LoadResouce("player", "statek.png");
	UniquePtr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
	sprite->setTexture(*tex);

	Date date(20, 6, 2000);
	Log(date.ToWithMonthsString());

	GameClock *clock = &*GameClock::GetInstance();
	clock->Initialize();

	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
			{
				clock->SetSpeedUp();
				Log("Speed UP to: " + clock->GetSpeedLvByString());
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::O)
			{
				clock->SetSpeedDown();
				Log("Speed UP to: " + clock->GetSpeedLvByString());
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				clock->SetPause();
				Log("Speed UP to: " + clock->GetSpeedLvByString());
			}
		}
		gameTimer->UpdateElapsedTime();
		fpsCounter->Update();

		clock->Update(gameTimer->GetElapsedTime());

		window->clear(sf::Color::Blue);

		window->draw(*sprite);

		fpsCounter->Draw(*window);
		clock->Draw(*window);
		window->display();
	}

	delete window;
	window = nullptr;

	return 0;
}