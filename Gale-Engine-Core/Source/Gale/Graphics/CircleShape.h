#pragma once
#include <SFML/Graphics.hpp>

namespace ge 
{
	class CircleShape : public sf::CircleShape
	{
	public:
		CircleShape(float radius = 0, std::size_t pointCount = 30);

		void FlipX();
		void FlipY();

		int zOrder = 0;

		virtual void start() {};
		virtual void update() {};
	};
}