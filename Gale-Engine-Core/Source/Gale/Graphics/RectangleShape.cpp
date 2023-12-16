#include "RectangleShape.h"

ge::RectangleShape::RectangleShape(const sf::Vector2f& size) : sf::RectangleShape(size) {}

void ge::RectangleShape::FlipX()
{
	float currentScale = getScale().x;
	setScale(-getScale().x, getScale().y);

	if (currentScale > 0)
		move(getGlobalBounds().width, 0);
	else
		move(-getGlobalBounds().width, 0);
}

void ge::RectangleShape::FlipY()
{
	float currentScale = getScale().y;
	setScale(getScale().x, -getScale().y);

	if (currentScale > 0)
		move(0, getGlobalBounds().height);
	else
		move(0, -getGlobalBounds().height);
}