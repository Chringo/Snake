#include <Amadeus\System.h>
System::System() {}
System::~System() {}

int System::Init()
{
	// TODO - Error cases
	m_window.create(sf::VideoMode(1280, 720), "TITLE"/*, sf::Style::None*/);
	m_window.setVerticalSyncEnabled(true);
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
					if (e.key.code == sf::Keyboard::F1)
					{
						m_game.Init();
					}
					m_game.HandleInput(e);
					break;
				}
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
		//this->PerformanceTests(m_clock.getElapsedTime().asSeconds());
		m_game.Update(e, m_clock.restart().asSeconds());
		this->Render();
	}
	return 0;
}

int System::Shutdown()
{
	m_game.Shutdown();
	return 0;
}

void System::Render()
{
	// TODO - Off-screen drawing tests
	m_window.clear(sf::Color::Black);
	m_window.draw(m_game);
	m_window.display();
}

void System::PerformanceTests(const float lastframe)
{
	m_numframes++;
	m_elapsedtime += lastframe;
	float average = m_numframes / m_elapsedtime;
	if (m_numframes > 100)// Skip the first 100 frames
	{
		if (m_shortest < average)
			m_shortest = average;
		if (m_longest > average)
			m_longest = average;
	}

	if (m_elapsedtime > 1)
	{
		system("cls");// Should avoid calls to system but it gets the job done...
		std::printf("%.1f\n", average);
		std::printf("%.1f\n", m_longest);
		std::printf("%.1f\n", m_shortest);
		m_numframes = 0;
		m_elapsedtime = 0;
	}
}