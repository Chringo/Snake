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
					std::printf("%d", e.key.code);
				}
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
		//PerformanceTests(m_clock.getElapsedTime().asSeconds());
		m_game.Update(e, m_clock.restart().asSeconds());
		Render();
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
	float averageframe = m_elapsedtime / m_numframes;
	if (m_longestframe < lastframe)
		m_longestframe = lastframe;
	if (m_shortestframe > lastframe)
		m_shortestframe = lastframe;

	std::printf("%.6f\n", averageframe);
	std::printf("%.6f\n", m_longestframe);
	std::printf("%.6f\n", m_shortestframe);
	system("cls");// Should avoid calls to system but it gets the job done...
}