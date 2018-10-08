#pragma once
#include <SFML/System/Vector2.hpp>

struct Vector2
{
	float x, y;

	Vector2() noexcept;
	Vector2(float x, float y)noexcept;
	Vector2(const Vector2& vector) noexcept;
	Vector2(Vector2&& vector) noexcept;

	Vector2(const sf::Vector2f& vec) noexcept;
	Vector2(const sf::Vector2u& vec) noexcept;
	Vector2(const sf::Vector2i& vec) noexcept;

	//Convert Vector to string "x: x, y: y"
	std::string GetVectorToString() const noexcept;

	//explicit cast to sf::Vector2f
	explicit operator sf::Vector2f() noexcept;
	//explicit cast to sf::Vector2i
	explicit operator sf::Vector2i() noexcept;
	//explicit cast to sf::Vector2u
	explicit operator sf::Vector2u() noexcept;

	//explicit cast to sf::Vector2f
	explicit operator sf::Vector2f() const noexcept;
	//explicit cast to sf::Vector2i
	explicit operator sf::Vector2i() const noexcept;
	//explicit cast to sf::Vector2u
	explicit operator sf::Vector2u() const noexcept;

	Vector2& operator +=(const Vector2& vec) noexcept;
	Vector2& operator -=(const Vector2& vec) noexcept;

	bool operator ==(const Vector2& vec) noexcept;
	bool operator !=(const Vector2& vec) noexcept;
	friend bool operator >(const Vector2&a, const Vector2&b) noexcept;

	friend bool operator <(const Vector2&a, const Vector2&b) noexcept;

	friend bool operator  >= (const Vector2&a, const Vector2&b) noexcept;

	friend bool operator <=(const Vector2&a, const Vector2&b) noexcept;

	Vector2 & operator = (const Vector2 &a) noexcept;
};
