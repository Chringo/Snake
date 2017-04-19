#include <Amadeus\System.h>

System::System(){}
System::~System(){}

int System::Init()
{
	window.create(sf::VideoMode(200, 200), "SFML");
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
	return 0;
}

int System::Run()
{
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
	return 0;
}

int System::Shutdown()
{
	return 0;
}
