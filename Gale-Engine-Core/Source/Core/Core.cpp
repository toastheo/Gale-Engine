#include "Core.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Core {

	void PrintHelloWorld()
	{
		std::cout << "Hello World!\n";
		std::cin.get();
	}

	void TestSFML()
	{
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
	}
}