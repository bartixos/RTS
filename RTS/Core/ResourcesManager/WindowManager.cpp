#include "stdafx.h"
#include "WindowManager.h"
#include "Core/Math/Vector2.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

sf::RenderWindow * WindowManager::GetWindow()  noexcept
{
	if (window)
	{
		return &*window;
	}
	else
	{
		return CreateWindow();
	}
}

sf::RenderWindow * WindowManager::CreateWindow(const Vector2& size, const std::string & title) noexcept
{
	if (window)
	{
		return &*window;
	}
	else
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y)), title);
		this->title = title;
		return &*window;
	}
}

Vector2  WindowManager::GetWindowSize()  noexcept
{
	if (window)
	{
		return std::move(Vector2(window->getSize()));
	}
	else
	{
		Log("Create First Window to change size");
		return Vector2();
	}
}

void WindowManager::SetWindowSize(const Vector2&  size) noexcept
{
	if (window)
	{
		window->setSize(static_cast<sf::Vector2u>(size));
	}
}

std::string  WindowManager::GetString() const noexcept
{
	return std::move(std::string(title));
}

void WindowManager::SetTitle(const std::string & title) noexcept
{
	this->title = title;
	window->setTitle(title);
}