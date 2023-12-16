#include "Text.h"

void ge::Text::FlipX()
{
	float currentScale = getScale().x;
	setScale(-getScale().x, getScale().y);

	if (currentScale > 0)
		move(getGlobalBounds().width, 0);
	else
		move(-getGlobalBounds().width, 0);
}

void ge::Text::FlipY()
{
	float currentScale = getScale().y;
	setScale(getScale().x, -getScale().y);

	if (currentScale > 0)
		move(0, getGlobalBounds().height);
	else
		move(0, -getGlobalBounds().height);
}
