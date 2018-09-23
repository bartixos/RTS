#include "stdafx.h"
#include "FpsCounter.h"
#include <SFML/Graphics.hpp>
#include "Core/ResourcesManager/FontManager.h"

FpsCounter::FpsCounter()
{
}

void FpsCounter::Update() noexcept
{
	frameCount++;

	if (delayTimer->getElapsedTime().asSeconds() > 0.2f)
	{
		fps = frameCount / fpsTimer->restart().asSeconds();
		frameCount = 0;
		delayTimer->restart();
	}
	text->setString("FPS: " + std::to_string(static_cast<int>(fps)));
}

void FpsCounter::Draw(sf::RenderWindow & window) noexcept
{
	window.draw(*text);
}

void FpsCounter::Initialize() noexcept
{
	font = &*FontManager::GetInstance()->LoadResouce("default", "Font.ttf");

	text = std::make_unique<sf::Text>();
	text->setFont(*font);
	text->setCharacterSize(16);
	text->setFillColor(sf::Color::White);
	text->setOutlineColor(sf::Color::Black);
	text->setOutlineThickness(2);
	text->setPosition(0, 0);

	delayTimer = std::make_unique<sf::Clock>();
	fpsTimer = std::make_unique<sf::Clock>();
}