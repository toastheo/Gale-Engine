#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Sprite.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "ConvexShape.h"
#include "Text.h"

namespace ge 
{
	class Scene
	{
	public:
		Scene() {};
		~Scene() {};

		virtual void start() = 0;
		virtual void update() = 0;

		void updateLogic();
		void render(std::shared_ptr<sf::RenderWindow> renderWindow);

	protected:
		bool addSprite(std::shared_ptr<ge::Sprite>, const std::string& texturePath);
		bool addCircleShape(std::shared_ptr<ge::CircleShape> shape, const std::string& texturePath = "");
		bool addRectangleShape(std::shared_ptr<ge::RectangleShape> shape, const std::string& texturePath = "");
		bool addConvexShape(std::shared_ptr<ge::ConvexShape> shape, const std::string& texturePath = "");
		bool addText(std::shared_ptr<ge::Text> text, const std::string& fontPath);

	private:
		struct TextureAndPath
		{
			std::shared_ptr<sf::Texture> texture;
			std::string texturePath;
		};

		struct FontAndPath
		{
			std::shared_ptr<sf::Font> font;
			std::string fontPath;
		};

		enum class ObjectType
		{
			Sprite,
			CircleShape,
			RectangleShape,
			ConvexShape,
			Text
		};

		std::vector<std::tuple<int, std::shared_ptr<void>, ObjectType>> drawableObjects;
		std::vector<TextureAndPath> textures;
		std::vector<FontAndPath> fonts;

		void sortVector();
	};
}
