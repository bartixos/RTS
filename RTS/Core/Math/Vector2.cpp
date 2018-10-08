#include "Vector2.h"
#include <SFML/System/Vector2.hpp>

Vector2::Vector2()noexcept
	:x(0),
	y(0)
{
}

Vector2::Vector2(float x, float y) noexcept
	:x(x),
	y(y)
{
}

Vector2::Vector2(const Vector2& vec) noexcept
	:x(vec.x),
	y(vec.y)
{
}

Vector2::Vector2(Vector2&& vec) noexcept
	:x(std::move(vec.x)),
	y(std::move(vec.y))
{
}

Vector2::Vector2(const sf::Vector2f& vec) noexcept
	:x(vec.x),
	y(vec.y)
{
}

Vector2::Vector2(const sf::Vector2u & vec) noexcept
	:x(static_cast<float>(vec.x)),
	y(static_cast<float>(vec.y))
{
}

Vector2::Vector2(const sf::Vector2i & vec) noexcept
	:x(static_cast<float>(vec.x)),
	y(static_cast<float>(vec.y))
{
}

std::string Vector2::GetVectorToString() const noexcept
{
	return std::move(std::string("x: " + std::to_string(x) + " y: " + std::to_string(y) + "\n"));
}

Vector2::operator sf::Vector2f() noexcept
{
	return std::move(sf::Vector2f(x, y));
}

Vector2::operator sf::Vector2i() noexcept
{
	return std::move(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)));
}

Vector2::operator sf::Vector2u() noexcept
{
	return std::move(sf::Vector2u(static_cast<unsigned int>(x), static_cast<unsigned int>(y)));
}

Vector2::operator sf::Vector2f() const noexcept
{
	return std::move(sf::Vector2f(x, y));
}

Vector2::operator sf::Vector2i() const noexcept
{
	return std::move(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)));
}

Vector2::operator sf::Vector2u() const noexcept
{
	return std::move(sf::Vector2u(static_cast<unsigned int>(x), static_cast<unsigned int>(y)));
}

Vector2 & Vector2::operator+=(const Vector2 & vec) noexcept
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & vec) noexcept
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

bool Vector2::operator==(const Vector2 & vec) noexcept
{
	if (x == vec.x && vec.y == y)
		return true;
	else
		return false;
}

bool Vector2::operator!=(const Vector2 & vec) noexcept
{
	if (*this == vec)
		return false;
	else
		return true;
}

Vector2 & Vector2::operator=(const Vector2 & a) noexcept
{
	if (*this != a)
	{
		x = a.x;
		y = a.y;
	}
	return *this;
}

bool operator>(const Vector2 & a, const Vector2 & b) noexcept
{
	if (a.x > b.x && a.y > b.y)
	{
		return true;
	}
	else return false;
}

bool operator<(const Vector2 & a, const Vector2 & b) noexcept
{
	if (a.x < b.x && a.y < b.y)
	{
		return true;
	}
	else return false;
}

bool operator>=(const Vector2 & a, const Vector2 & b) noexcept
{
	if (a.x >= b.x && a.y >= b.y)
	{
		return true;
	}
	else return false;
}

bool operator<=(const Vector2 & a, const Vector2 & b) noexcept
{
	if (a.x <= b.x && a.y <= b.y)
	{
		return true;
	}
	else return false;
}