#include "Engine.h"
#include <iostream>

ge::GameEngine* ge::GameEngine::gameEngine = nullptr;

void ge::GameEngine::setWindow(unsigned int width, unsigned int height, const std::string& title, bool verticalSync)
{
	m_renderWindow->create(sf::VideoMode(width, height), title);
	m_renderWindow->setVerticalSyncEnabled(verticalSync);
}

void ge::GameEngine::setScene(std::shared_ptr<Scene> scene)
{
	m_scene = scene;
	m_scene->start();
}

void ge::GameEngine::start()
{
	while (m_renderWindow->isOpen())
		updateLoop();
}

ge::GameEngine::GameEngine()
{
	m_renderWindow->create(sf::VideoMode(1920, 1080), "RenderWindow");
	m_renderWindow->setVerticalSyncEnabled(false);
	m_gameIsRunning = true;
}

ge::GameEngine::~GameEngine()
{
	if (m_thread.joinable())
		m_thread.join();
}

void ge::GameEngine::updateLoop()
{
	if (!m_scene)
	{
		std::cout << "Scene Pointer is empty. Make sure to load a scene before starting the Game Engine.\nClosing window."; 
		m_renderWindow->close();
		return;
	}

	if (!m_threadStarted)
	{
		m_thread = std::thread(&GameEngine::renderThread, this);
		m_threadStarted = true;
	}

	m_renderWindow->setActive(false);

	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_gameIsRunning = false;

			if (m_thread.joinable())
				m_thread.join();

			m_renderWindow->close();
		}
	}
}

void ge::GameEngine::renderThread()
{
	if (!m_scene)
		return;

	m_renderWindow->setActive(true);

	while (m_gameIsRunning && m_renderWindow->isOpen())
	{
		m_renderWindow->clear();

		m_scene->update();
		m_scene->render(m_renderWindow);

		m_renderWindow->display();
	}
}
