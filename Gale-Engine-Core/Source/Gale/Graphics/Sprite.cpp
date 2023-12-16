#include "Sprite.h"

ge::Sprite::Sprite() : sf::Sprite() {}

void ge::Sprite::FlipX()
{
	float currentScale = getScale().x;
	setScale(-getScale().x, getScale().y);

	if (currentScale > 0)
		move(getGlobalBounds().width, 0);
	else
		move(-getGlobalBounds().width, 0);
}

void ge::Sprite::FlipY()
{
	float currentScale = getScale().y;
	setScale(getScale().x, -getScale().y);

	if (currentScale > 0)
		move(0, getGlobalBounds().height);
	else
		move(0, -getGlobalBounds().height);
}

