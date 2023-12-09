#pragma once
#include <SFML/Graphics.hpp>

namespace ge 
{
	class Scene
	{
	public:
		Scene() {};
		~Scene() {};

		virtual void start() = 0;
		virtual void update() = 0;

		void render(std::shared_ptr<sf::RenderWindow> renderWindow);
	};
}
