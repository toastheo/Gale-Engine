#pragma once
#include <SFML/Graphics.hpp>

namespace ge
{
	class RectangleShape : public sf::RectangleShape
	{
	public:
		RectangleShape(const sf::Vector2f& size = sf::Vector2f(0, 0));

		void FlipX();
		void FlipY();

		int zOrder = 0;

		virtual void start() {};
		virtual void update() {};
	};
}