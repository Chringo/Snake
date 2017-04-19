#include <Amadeus\System.h>
System::System() {}
System::~System() {}

void System::Render()
{
	m_window.clear();
	m_window.draw(shape);
	m_window.display();
}

int System::Init()
{
	m_window.create(sf::VideoMode(1280, 720), "TITLE"/*, sf::Style::None*/);
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
	return 0;
}

int System::Run()
{
	while (m_window.isOpen())
	{
		// Events triggered since last iteration
		sf::Event e;
		while (m_window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::KeyPressed:
				if (e.key.code != sf::Keyboard::Escape)// 36 = ESC
				{
					std::printf("%d", e.key.code);
				}
				// else close
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
		Render();
	}
	return 0;
}

int System::Shutdown()
{
	return 0;
}
