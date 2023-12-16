#include "Gale/System/Engine.h"
#include "Gale/System/Scene.h"
using namespace ge;

class Testszene : public Scene
{
	std::shared_ptr<Sprite> blueChicken = std::make_shared<Sprite>();
	std::shared_ptr<Sprite> blueChicken2 = std::make_shared<Sprite>();
	std::shared_ptr<CircleShape> redCircle = std::make_shared<CircleShape>(100);
	std::shared_ptr<RectangleShape> blueRectangle = std::make_shared<RectangleShape>(sf::Vector2f(200.f, 100.f));
	std::shared_ptr<ConvexShape> convex = std::make_shared<ConvexShape>();
	std::shared_ptr<Text> helloWorld = std::make_shared<Text>();

	virtual void start() override
	{
		addSprite(blueChicken, "BlueChickenIdle-Sheet.png");
		addSprite(blueChicken2, "BlueChickenIdle-Sheet.png");
		addCircleShape(redCircle);
		addRectangleShape(blueRectangle);
		addConvexShape(convex);
		addText(helloWorld, "Arimo-VariableFont_wght.ttf");

		blueChicken->setScale(10.f, 10.f);
		blueChicken->setTextureRect(sf::IntRect(0, 0, blueChicken->getLocalBounds().width / 5, blueChicken->getLocalBounds().height));
		blueChicken->move(blueChicken->getGlobalBounds().width / 2, 0);
		blueChicken->zOrder = 1;

		blueChicken2->setScale(10.f, 10.f);
		blueChicken2->move(0, blueChicken2->getGlobalBounds().height);

		redCircle->setFillColor(sf::Color::Red);
		redCircle->move(0, 300.f);
		redCircle->zOrder = 10;

		blueRectangle->setFillColor(sf::Color::Blue);
		blueRectangle->zOrder = -10;

		convex->setPointCount(5);
		convex->setPoint(0, sf::Vector2f(0.f, 0.f));
		convex->setPoint(1, sf::Vector2f(150.f, 10.f));
		convex->setPoint(2, sf::Vector2f(120.f, 90.f));
		convex->setPoint(3, sf::Vector2f(30.f, 100.f));
		convex->setPoint(4, sf::Vector2f(0.f, 50.f));

		helloWorld->setPosition(1000.f, 600.f);
		helloWorld->setString("Hello World!");
		helloWorld->setFillColor(sf::Color::White);
		helloWorld->setCharacterSize(60);
	}

	virtual void update() override
	{
		blueChicken->move(0.f, 1.f);
	}
};

int main()
{
	GameEngine* gameEngine = GameEngine::getEngine();
	gameEngine->setWindow(1920, 1080, "Mein Spiel", true);
	gameEngine->setScene(std::make_shared<Testszene>());
	gameEngine->start();

	return 0;
}