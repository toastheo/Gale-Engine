#include "Scene.h"
#include <iostream>

void ge::Scene::updateLogic()
{
	for (auto& obj : drawableObjects)
	{
		switch (std::get<2>(obj))
		{
		case ObjectType::Sprite:
			std::static_pointer_cast<ge::Sprite>(std::get<1>(obj))->update();
			break;
		case ObjectType::CircleShape:
			std::static_pointer_cast<ge::CircleShape>(std::get<1>(obj))->update();
			break;
		case ObjectType::RectangleShape:
			std::static_pointer_cast<ge::RectangleShape>(std::get<1>(obj))->update();
			break;
		case ObjectType::ConvexShape:
			std::static_pointer_cast<ge::ConvexShape>(std::get<1>(obj))->update();
			break;
		case ObjectType::Text:
			std::static_pointer_cast<ge::Text>(std::get<1>(obj))->update();
		}
	}
}

void ge::Scene::render(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	sortVector();

	for (auto& obj : drawableObjects)
	{
		switch (std::get<2>(obj))
		{
		case ObjectType::Sprite:
			renderWindow->draw(*std::static_pointer_cast<ge::Sprite>(std::get<1>(obj)));
			break;
		case ObjectType::CircleShape:
			renderWindow->draw(*std::static_pointer_cast<ge::CircleShape>(std::get<1>(obj)));
			break;
		case ObjectType::RectangleShape:
			renderWindow->draw(*std::static_pointer_cast<ge::RectangleShape>(std::get<1>(obj)));
			break;
		case ObjectType::ConvexShape:
			renderWindow->draw(*std::static_pointer_cast<ge::ConvexShape>(std::get<1>(obj)));
			break;
		case ObjectType::Text:
			renderWindow->draw(*std::static_pointer_cast<ge::Text>(std::get<1>(obj)));
		}
	}
}

bool ge::Scene::addSprite(std::shared_ptr<ge::Sprite> sprite, const std::string& texturePath)
{
	// if sprite already exists in the vector
	for (auto& obj : drawableObjects)
	{
		if (std::get<2>(obj) == ObjectType::Sprite)
		{
			if (sprite == std::static_pointer_cast<ge::Sprite>(std::get<1>(obj)))
			{
				std::cout << "Error: You can't add the same sprite twice" << std::endl;
				return false;
			}
		}
	}

	// check if texture is already existing
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		if (textures[i].texturePath == texturePath)
		{
			sprite->setTexture(*(textures[i].texture));
			drawableObjects.push_back(std::make_tuple(sprite->zOrder, std::static_pointer_cast<void>(sprite), ObjectType::Sprite));
			sprite->start();
			return true;
		}
	}

	// if not create texture and store it 
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
	if (!texture->loadFromFile(texturePath))
		return false;

	TextureAndPath newTexture;
	newTexture.texture = texture;
	newTexture.texturePath = texturePath;
	sprite->setTexture(*texture);

	textures.push_back(newTexture);
	drawableObjects.push_back(std::make_tuple(sprite->zOrder, std::static_pointer_cast<void>(sprite), ObjectType::Sprite));
	sprite->start();
	return true;
}

bool ge::Scene::addCircleShape(std::shared_ptr<ge::CircleShape> shape, const std::string& texturePath)
{
	// if shape already exists in the vector
	for (auto& obj : drawableObjects)
	{
		if (std::get<2>(obj) == ObjectType::CircleShape)
		{
			if (shape == std::static_pointer_cast<ge::CircleShape>(std::get<1>(obj)))
			{
				std::cout << "Error: You can't add the same circle shape twice" << std::endl;
				return false;
			}
		}
	}

	// if there is a custom texture
	if (texturePath != "")
	{
		// check if texture is already existing
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			if (textures[i].texturePath == texturePath)
			{
				shape->setTexture(textures[i].texture.get());
				drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::CircleShape));
				shape->start();
				return true;
			}
		}

		// if not create texture and store it
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		if (!texture->loadFromFile(texturePath))
			return false;

		TextureAndPath newTexture;
		newTexture.texture = texture;
		newTexture.texturePath = texturePath;
		shape->setTexture(texture.get());
		textures.push_back(newTexture);
	}

	// add Circle Shape
	drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::CircleShape));
	shape->start();
	return true;
}

bool ge::Scene::addRectangleShape(std::shared_ptr<ge::RectangleShape> shape, const std::string& texturePath)
{
	// if shape already exists in the vector
	for (auto& obj : drawableObjects)
	{
		if (std::get<2>(obj) == ObjectType::RectangleShape)
		{
			if (shape == std::static_pointer_cast<ge::RectangleShape>(std::get<1>(obj)))
			{
				std::cout << "Error: You can't add the same rectangle shape twice" << std::endl;
				return false;
			}
		}
	}

	// if there is a custom texture
	if (texturePath != "")
	{
		// check if texture is already existing
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			if (textures[i].texturePath == texturePath)
			{
				shape->setTexture(textures[i].texture.get());
				drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::RectangleShape));
				shape->start();
				return true;
			}
		}

		// if not create texture and store it
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		if (!texture->loadFromFile(texturePath))
			return false;

		TextureAndPath newTexture;
		newTexture.texture = texture;
		newTexture.texturePath = texturePath;
		shape->setTexture(texture.get());
		textures.push_back(newTexture);
	}

	// add Rectangle Shape
	drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::RectangleShape));
	shape->start();
	return true;
}

bool ge::Scene::addConvexShape(std::shared_ptr<ge::ConvexShape> shape, const std::string& texturePath)
{
	// if shape already exists in the vector
	for (auto& obj : drawableObjects)
	{
		if (std::get<2>(obj) == ObjectType::ConvexShape)
		{
			if (shape == std::static_pointer_cast<ge::ConvexShape>(std::get<1>(obj)))
			{
				std::cout << "Error: You can't add the same convex shape twice" << std::endl;
				return false;
			}
		}
	}

	// if there is a custom texture
	if (texturePath != "")
	{
		// check if texture is already existing
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			if (textures[i].texturePath == texturePath)
			{
				shape->setTexture(textures[i].texture.get());
				drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::ConvexShape));
				shape->start();
				return true;
			}
		}

		// if not create texture and store it
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		if (!texture->loadFromFile(texturePath))
			return false;

		TextureAndPath newTexture;
		newTexture.texture = texture;
		newTexture.texturePath = texturePath;
		shape->setTexture(texture.get());
		textures.push_back(newTexture);
	}

	// add Convex Shape
	drawableObjects.push_back(std::make_tuple(shape->zOrder, std::static_pointer_cast<void>(shape), ObjectType::ConvexShape));
	shape->start();
	return true;
}

bool ge::Scene::addText(std::shared_ptr<ge::Text> text, const std::string& fontPath)
{
	// if text already exists in the vector
	for (auto& obj : drawableObjects)
	{
		if (std::get<2>(obj) == ObjectType::Text)
		{
			if (text == std::static_pointer_cast<ge::Text>(std::get<1>(obj)))
			{
				std::cout << "Error: You can't add the same text twice" << std::endl;
				return false;
			}
		}
	}

	// check if font is already existing
	for (unsigned int i = 0; i < fonts.size(); i++)
	{
		if (fonts[i].fontPath == fontPath)
		{
			text->setFont(*fonts[i].font);
			drawableObjects.push_back(std::make_tuple(text->zOrder, std::static_pointer_cast<void>(text), ObjectType::Text));
			text->start();
			return true;
		}
	}

	// if not create texture and store it 
	std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
	if (!font->loadFromFile(fontPath))
		return false;

	FontAndPath newFont;
	newFont.font = font;
	newFont.fontPath = fontPath;
	text->setFont(*font);

	fonts.push_back(newFont);
	drawableObjects.push_back(std::make_tuple(text->zOrder, std::static_pointer_cast<void>(text), ObjectType::Sprite));
	text->start();
	return true;
}

void ge::Scene::sortVector()
{
	for (auto& obj : drawableObjects)
	{
		switch (std::get<2>(obj))
		{
		case ObjectType::Sprite:
			std::get<0>(obj) = std::static_pointer_cast<ge::Sprite>(std::get<1>(obj))->zOrder;
			break;
		case ObjectType::CircleShape:
			std::get<0>(obj) = std::static_pointer_cast<ge::CircleShape>(std::get<1>(obj))->zOrder;
			break;
		case ObjectType::RectangleShape:
			std::get<0>(obj) = std::static_pointer_cast<ge::RectangleShape>(std::get<1>(obj))->zOrder;
			break;
		case ObjectType::ConvexShape:
			std::get<0>(obj) = std::static_pointer_cast<ge::ConvexShape>(std::get<1>(obj))->zOrder;
			break;
		case ObjectType::Text:
			std::get<0>(obj) = std::static_pointer_cast<ge::Text>(std::get<1>(obj))->zOrder;
		}
	}

	std::sort(drawableObjects.begin(), drawableObjects.end(), [](const auto& a, const auto& b) {
		return std::get<0>(a) < std::get<0>(b);
	});
}
