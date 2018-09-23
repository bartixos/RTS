#pragma once
#include <SFML/Graphics/Font.hpp>
#include "AResourceManager.h"
#include "Utility/ASingleton.h"

class FontManager : public AResourceManager<sf::Font>,
	public ASingleton<FontManager>
{
};