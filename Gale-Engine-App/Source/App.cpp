#include "Core/Engine.h"
#include "Core/Scene.h"

#include <iostream>

using namespace ge;

class Testscene : public Scene 
{
	virtual void start() override
	{
		std::cout << "Testscene started!" << std::endl;
	}

	virtual void update() override
	{
		
	}
};

int main()
{
	GameEngine* gameEngine = GameEngine::getEngine();
	
	gameEngine->setWindow(800, 600, "This is my Window", true);
	gameEngine->setScene(std::make_shared<Testscene>());
	gameEngine->start();

	return 0;
}