#pragma once
#include "Utility/ASingleton.h"
#include "Utility/Define.h"
#include "Core/Math/Vector2.h"

namespace sf
{
	class RenderWindow;
}

class WindowManager : public ASingleton<WindowManager>
{
	UniquePtr<sf::RenderWindow> window;
	std::string title;
public:

	sf::RenderWindow *GetWindow()  noexcept;
	sf::RenderWindow *CreateWindow(const Vector2& size = Vector2(800, 600), const std::string& title = "RandomTitle")  noexcept;
	Vector2 GetWindowSize() noexcept;
	void SetWindowSize(const Vector2& size) noexcept;

	std::string GetString() const noexcept;
	void SetTitle(const std::string &title) noexcept;
};
