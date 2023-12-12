#pragma once
#include <SFML/Graphics.hpp>

namespace ge
{
	class Sprite : public sf::Sprite
	{
	public:
		Sprite();

		void FlipX();
		void FlipY();

		int zOrder = 0;

		virtual void start() {};
		virtual void update() {};
	};
}