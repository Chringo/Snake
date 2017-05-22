#include <Amadeus\System.h>
#define NUMBER_OF_MAPS 3
System::System() {}
System::~System() {}

int System::Init()
{
	// TODO - Error cases
	m_window.create(sf::VideoMode(1280, 720), "TITLE"/*, sf::Style::None*/);
	m_vsync = true;
	m_performance = false;
	m_mapchosen = false;
	m_gamerunning = false;
	m_window.setVerticalSyncEnabled(m_vsync);
	m_data.ImportFont("arcade/ARCADE.ttf");

	m_playername.setString(this->PlayerSetsName());
	//m_playername.setString("Dev");
	//std::string temp = m_playername.getString();
	//std::printf("Player: %s\n", temp.c_str());
	if (m_window.isOpen())
	{
		m_game.setFileHandler(&m_data);
		m_game.setMap("default.txt");
		m_game.StaticSetup();
		
		m_data.setName(m_playername.getString());
		m_data.LoadLeaderboard(m_leaderboard);
		this->MenuSetup(NUMBER_OF_MAPS);

		// Restart clock to avoid a very high dt on the first frame
		m_clock.restart();
	}
	return 0;
}

sf::String System::PlayerSetsName()
{
	int i = 0;
	float whalfglobal = 1280 / 2;
	float hthirdglobal = 720 / 3;
	m_center[i].setFont(*m_data.getFont());
	m_center[i].setString("Create a username:");
	m_center[i].setCharacterSize(80); // in pixels, not points!
	m_center[i].setFillColor(sf::Color(153, 153, 102));
	float lwidth = m_center[i].getLocalBounds().width;
	float top = hthirdglobal - m_center[i].getLocalBounds().height;
	m_center[i].setPosition(sf::Vector2f(whalfglobal - (lwidth / 2), top));
	top = m_center[0].getLocalBounds().height;
	i++;
	m_center[i].setFont(*m_data.getFont());
	m_center[i].setString("");
	m_center[i].setCharacterSize(80); // in pixels, not points!
	m_center[i].setFillColor(sf::Color(102, 102, 51));
	top = m_center[0].getPosition().y + (top * 2);
	
	sf::String name = "";
	while (m_window.isOpen())
	{
		sf::Event e;
		while (m_window.pollEvent(e))
		{
			if (e.type == sf::Event::TextEntered)
			{
				//std::printf("%d ", e.text.unicode);
				if (e.text.unicode >= 48 && e.text.unicode <= 57 ||	// Numbers
					e.text.unicode >= 65 && e.text.unicode <= 90 ||	// Uppercase
					e.text.unicode >= 97 && e.text.unicode <= 122)	// Lowercase
				{
					name.insert(name.getSize(), e.text.unicode);
					m_center[i].setString(name);
					lwidth = m_center[i].getLocalBounds().width;
					m_center[i].setPosition(sf::Vector2f(whalfglobal - (lwidth / 2), top));
				}
			}
			else if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::BackSpace)
				{
					if (name.getSize() == 0)
						m_center[i].setString("");
					else
						name.erase(name.getSize() - 1);
					m_center[i].setString(name);
					lwidth = m_center[i].getLocalBounds().width;
					m_center[i].setPosition(sf::Vector2f(whalfglobal - (lwidth / 2), top));
				}
				else if (e.key.code == sf::Keyboard::Escape)
				{
					m_window.close();
				}
				else if (e.key.code == sf::Keyboard::Return)
				{
					return name;
				}
			}
			else if (e.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
		m_window.clear(sf::Color::Black);
		m_window.draw(m_center[0]);
		m_window.draw(m_center[1]);
		m_window.display();
	}
	return name;
}

int System::Run()
{
	while (m_window.isOpen())
	{
		this->HandleEvents();
		if (m_performance)
			this->PerformanceTests(m_clock.getElapsedTime().asSeconds());
		if (m_gamerunning)
		{
			int temp = m_game.Update(m_clock.restart().asSeconds());
			if (temp == 1)
			{
				m_window.close();
			}
			else if (temp == 2)
			{
				m_gamerunning = false;
				m_mapchosen = false;
				m_data.LoadLeaderboard(m_leaderboard);
				float top = 125;
				const float wglobal = 1280;
				for (int i = 1; i < 6; i++)
				{
					const float lwidth = m_leaderboard[i].getLocalBounds().width;
					m_leaderboard[i].setPosition(sf::Vector2f(wglobal - lwidth - 75, top));
					top += 30;
				}
			}
		}
		else
		{
			m_clock.restart().asSeconds();
		}
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
	m_window.clear(sf::Color::Black);
	if (m_gamerunning)
	{
		m_window.draw(m_game);
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			m_window.draw(m_leaderboard[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			m_window.draw(m_center[i]);
		}
		for (int i = 0; i < NUMBER_OF_MAPS; i++)
		{
			m_window.draw(m_mapoptions[i]);
		}
		m_window.draw(m_playername);
	}
	m_window.display();
}

void System::HandleEvents()
{
	// Events triggered since last iteration
	sf::Event e;
	while (m_window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::MouseButtonPressed:
			if (!e.mouseButton.button)
			{
				this->MouseEvent(e.mouseButton.x, e.mouseButton.y);
			}
			break;
		case sf::Event::KeyPressed:
			// If escape was pressed go to next case and close window
			if (e.key.code != sf::Keyboard::Escape)// 36 = ESC
			{
				if (e.key.code == sf::Keyboard::F1)//TEST
				{
					m_game.Init();
					m_gamerunning = true;
				}
				else if (e.key.code == sf::Keyboard::F2)
				{
					m_vsync = !m_vsync;
					m_window.setVerticalSyncEnabled(m_vsync);
				}
				else if (e.key.code == sf::Keyboard::F3)
				{
					m_performance = !m_performance;
				}
				if (m_gamerunning)
				{
					m_game.HandleInput(e);
				}
				break;
			}
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

void System::MouseEvent(int x, int y)
{
	int target = -1;
	const sf::FloatRect exit = m_center[2].getGlobalBounds();
	if (x > exit.left && x < (exit.left + exit.width) &&
		y > exit.top && y < (exit.top + exit.height))
	{
		m_window.close();
	}
	if (!m_mapchosen)
	{
		for (int i = 0; i < NUMBER_OF_MAPS; i++)
		{
			const sf::FloatRect bounds = m_mapoptions[i].getGlobalBounds();
			if (x > bounds.left && x < (bounds.left + bounds.width) &&
				y > bounds.top && y < (bounds.top + bounds.height))
			{
				m_mapoptions[i].setFillColor(sf::Color(204, 204, 0));
				target = i;
				m_mapchosen = true;
			}
			else
			{
				m_mapoptions[i].setFillColor(sf::Color(102, 102, 51));
			}
		}
		switch (target)
		{
		case 0:
			m_game.setMap("default.txt");
			break;
		case 1:
			m_game.setMap("map2.txt");
			break;
		case 2:
			m_game.setMap("small.txt");
			break;
		default:
			m_mapchosen = false;
			break;
		}
		if (m_mapchosen)
		{
			m_center[1].setFillColor(sf::Color(102, 102, 51));
		}
		else
		{
			m_center[1].setFillColor(sf::Color(51, 51, 0));
		}
	}
	else
	{
		const sf::FloatRect bounds = m_center[1].getGlobalBounds();
		if (x > bounds.left && x < (bounds.left + bounds.width) &&
			y > bounds.top && y < (bounds.top + bounds.height))
		{
			m_gamerunning = true;
			m_game.Init();
		}
		m_mapchosen = false;
		m_center[1].setFillColor(sf::Color(51, 51, 0));
		for (int i = 0; i < NUMBER_OF_MAPS; i++)
		{
			m_mapoptions[i].setFillColor(sf::Color(102, 102, 51));
		}
	}
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

void System::MenuSetup(int numberofmaps)
{
	int i = 0;
	const float wglobal = 1280;
	const float hglobal = 720;

	m_playername.setFont(*m_data.getFont());
	m_playername.setCharacterSize(45); // in pixels, not points!
	m_playername.setFillColor(sf::Color(153, 153, 102));
	float lwidth = m_playername.getLocalBounds().width;
	float top = 80;
	m_playername.setPosition(sf::Vector2f(lwidth + 65, top));

	m_leaderboard[i].setFont(*m_data.getFont());
	m_leaderboard[i].setString("Leaderboard");
	m_leaderboard[i].setCharacterSize(m_playername.getCharacterSize());
	m_leaderboard[i].setFillColor(sf::Color(153, 153, 102));
	lwidth = m_leaderboard[i].getLocalBounds().width;
	m_leaderboard[i].setPosition(sf::Vector2f(wglobal - lwidth - 65, top));
	top += 45;
	for (i++; i < 6; i++)
	{
		m_leaderboard[i].setFont(*m_data.getFont());
		m_leaderboard[i].setCharacterSize(30); // in pixels, not points!
		m_leaderboard[i].setFillColor(sf::Color(153, 153, 102));
		lwidth = m_leaderboard[i].getLocalBounds().width;
		m_leaderboard[i].setPosition(sf::Vector2f(wglobal - lwidth - 75, top));
		top += 30;
	}

	i = 0;
	m_center[i].setFont(*m_data.getFont());
	m_center[i].setString("Snake");
	m_center[i].setCharacterSize(165); // in pixels, not points!
	m_center[i].setFillColor(sf::Color(153, 153, 102));
	lwidth = m_center[i].getLocalBounds().width;
	m_center[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), -15));
	top = 140;
	i++;
	m_center[i].setFont(*m_data.getFont());
	m_center[i].setString("Start");
	m_center[i].setCharacterSize(80); // in pixels, not points!
	m_center[i].setFillColor(sf::Color(51, 51, 0));
	lwidth = m_center[i].getLocalBounds().width;
	m_center[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), top));
	i++;
	m_center[i].setFont(*m_data.getFont());
	m_center[i].setString("Exit game");
	m_center[i].setCharacterSize(80); // in pixels, not points!
	m_center[i].setFillColor(sf::Color(102, 102, 51));
	lwidth = m_center[i].getLocalBounds().width;
	top = m_center[i].getLocalBounds().height;
	m_center[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), hglobal - (top * 2)));

	i = 0;
	top = 230;
	m_mapoptions[i].setFont(*m_data.getFont());
	m_mapoptions[i].setString("MAP1");
	m_mapoptions[i].setCharacterSize(125); // in pixels, not points!
	m_mapoptions[i].setFillColor(sf::Color(102, 102, 51));
	lwidth = m_mapoptions[i].getLocalBounds().width;
	m_mapoptions[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), top));
	i++;
	top += 115;
	m_mapoptions[i].setFont(*m_data.getFont());
	m_mapoptions[i].setString("MAP2");
	m_mapoptions[i].setCharacterSize(125); // in pixels, not points!
	m_mapoptions[i].setFillColor(sf::Color(102, 102, 51));
	lwidth = m_mapoptions[i].getLocalBounds().width;
	m_mapoptions[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), top));
	i++;
	top += 115;
	m_mapoptions[i].setFont(*m_data.getFont());
	m_mapoptions[i].setString("MAP3");
	m_mapoptions[i].setCharacterSize(125); // in pixels, not points!
	m_mapoptions[i].setFillColor(sf::Color(102, 102, 51));
	lwidth = m_mapoptions[i].getLocalBounds().width;
	m_mapoptions[i].setPosition(sf::Vector2f((wglobal / 2) - (lwidth / 2), top));

}
