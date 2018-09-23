#pragma once
#include "AResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include "Utility/ASingleton.h"

class TextureManager :public AResourceManager<sf::Texture>,
	public ASingleton<TextureManager>
{
};
