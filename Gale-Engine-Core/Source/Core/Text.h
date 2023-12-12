#pragma once
#include <SFML/Graphics.hpp>

namespace ge
{
	class Text : public sf::Text
	{
	public:
		Text() {};

		void FlipX();
		void FlipY();

		int zOrder = 0;

		virtual void start() {};
		virtual void update() {};
	};
}