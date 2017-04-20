#include <Amadeus\System.h>
System::System() {}
System::~System() {}

int System::Init()
{
	// TODO - Error cases
	m_window.create(sf::VideoMode(1280, 720), "TITLE"/*, sf::Style::None*/);
	m_game.Init();
	// Restart clock to avoid a very high dt on the first frame
	m_clock.restart();
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
				// If escape was pressed go to next case and close window
				if (e.key.code != sf::Keyboard::Escape)// 36 = ESC
				{
					std::printf("%d", e.key.code);
				}
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
		m_game.Update(e, m_clock.restart().asSeconds());
		Render();
	}
	return 0;
}

int System::Shutdown()
{
	return 0;
}

void System::Render()
{
	m_window.clear();
	m_window.draw(m_game);
	m_window.display();
}