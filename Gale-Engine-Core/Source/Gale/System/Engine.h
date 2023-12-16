#pragma once
#include <thread>

#include "Scene.h"

namespace ge 
{
	class GameEngine 
	{
	public:
		static GameEngine* getEngine() 
		{
			if (gameEngine == nullptr)
				gameEngine = new GameEngine();

			return gameEngine;
		}

		void setWindow(unsigned int width = 1920, unsigned int height = 1080, const std::string& title = "RenderWindow", bool verticalSync = false);
		void setScene(std::shared_ptr<Scene> scene);
		void start();

	private:
		GameEngine();
		GameEngine(const GameEngine&) = delete;
		GameEngine& operator=(const GameEngine&) = delete;
		~GameEngine();

		static GameEngine* gameEngine;

		std::shared_ptr<Scene> m_scene;
		std::thread m_thread;
		std::shared_ptr<sf::RenderWindow> m_renderWindow = std::make_shared<sf::RenderWindow>();
		bool m_threadStarted = false;
		std::atomic<bool> m_gameIsRunning = false;

		void updateLoop();
		void renderThread();
	};
}