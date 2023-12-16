#pragma once
#include <SFML/Graphics.hpp>

namespace ge
{
	class ConvexShape : public sf::ConvexShape
	{
	public:
		ConvexShape(std::size_t pointCount = 0);

		void FlipX();
		void FlipY();

		int zOrder = 0;

		virtual void start() {};
		virtual void update() {};
	};
}