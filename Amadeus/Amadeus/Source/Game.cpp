#include <Amadeus\Game.h>
Game::Game()
{
	m_score = 0;
	m_gametime = 0;
	m_timesteps = 0;
	m_mapholder = nullptr;
	m_itemholder = nullptr;
	m_snakeholder = nullptr;
	m_colhandler = nullptr;
}
Game::~Game() {}

int Game::Init()
{
	Shutdown();
	m_score = 0;
	m_gametime = 0;
	m_timesteps = 0;
	m_difficulty = 0.35f;
	m_mapholder = new MapHolder();
	int height = 0;
	int width = 0;
	int **map = nullptr;
	// Import map from file system
	map = filehandler->LoadMap("default.txt", &height, &width, map);
	std::printf("Verifying scope: H%d - W%d - M[0][0] %d\n", height, width, map[0][0]);

	m_mapholder->Init(height, width, map);

	m_snakeholder = new SnakeHolder();
	m_snakeholder->Init(sf::Vector2i((width / 2), height / 2));
	const int kPieces = 12;
	std::printf("Creating %d SnakePieces on collision map\n", kPieces);
	for (int i = 0; i < kPieces; i++)
	{
		map[(height / 2)][(width / 2) + i] = 3;
	}

	m_itemholder = new ItemHolder();
	m_itemholder->Init(7, 1);

	m_notifier = new Notifier();
	m_colhandler = new CollisionHandler();
	m_notifier->Init(m_snakeholder, m_itemholder, m_colhandler);
	m_colhandler->Init(m_notifier, map, height, width);

	m_itemholder->Respawn(m_colhandler->getRandomPos());
	m_colhandler->UpdateItem(m_itemholder->getActiveItemPos());

	for (int i = 0; i < Keys::SIZE; i++)
	{
		m_keys[i] = false;
	}

	/* GRAPHICS */
	// Background
	if (m_backtexture.loadFromFile("../Assets/Textures/bgd_wood.png"))
	{
		m_backsprite.setTexture(m_backtexture);
		m_backsprite.setColor(sf::Color(50, 50, 50, 180));
	}
	// Pause screen
	m_operatemenu = false;
	int i = 0;
	m_pausemenu[i].setFont(*filehandler->getFont());
	m_pausemenu[i].setString("Pause screen");
	m_pausemenu[i].setCharacterSize(110); // in pixels, not points!
	m_pausemenu[i].setFillColor(sf::Color(51, 51, 0));
	m_pausemenu[i].setOutlineColor(sf::Color(153, 153, 102));
	m_pausemenu[i].setOutlineThickness(3);
	float lcenter = m_pausemenu[i].getLocalBounds().width / 2;
	float wcenter = 1280 / 2;
	float top = 25;
	m_pausemenu[i].move(sf::Vector2f(wcenter - lcenter, top));
	i++;
	m_pausemenu[i].setFont(*filehandler->getFont());
	m_pausemenu[i].setString("Go back to menu");
	m_pausemenu[i].setCharacterSize(75); // in pixels, not points!
	m_pausemenu[i].setFillColor(sf::Color::White);
	m_pausemenu[i].setOutlineColor(sf::Color::Black);
	m_pausemenu[i].setOutlineThickness(2);
	lcenter = m_pausemenu[i].getLocalBounds().width / 2;
	top += 100;
	m_pausemenu[i].move(sf::Vector2f(wcenter - lcenter, top));
	i++;
	m_pausemenu[i].setFont(*filehandler->getFont());
	m_pausemenu[i].setString("Exit game");
	m_pausemenu[i].setCharacterSize(75); // in pixels, not points!
	m_pausemenu[i].setFillColor(sf::Color(102, 102, 51));
	m_pausemenu[i].setOutlineColor(sf::Color::Black);
	m_pausemenu[i].setOutlineThickness(2);
	lcenter = m_pausemenu[i].getLocalBounds().width / 2;
	top += 75;
	m_pausemenu[i].move(sf::Vector2f(wcenter - lcenter, top));
	return 0;
}

int Game::Update(float dt)
{
	if (!m_keys[Keys::PAUSE])
	{
		m_gametime += dt;
		m_timesteps += dt;
		if (m_notifier->getLost())
		{
			std::printf("FINAL SCORE: %d\n", m_itemholder->getHighScore());
			filehandler->SaveSession(m_itemholder->getHighScore());
			this->Init();
		}

		if (m_timesteps > m_difficulty)
		{
			if (m_keys[Keys::A])
			{
				Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::LEFT);
				m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
				m_keys[Keys::A] = false;
			}
			else if (m_keys[Keys::D])
			{
				Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::RIGHT);
				m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
				m_keys[Keys::D] = false;
			}
			else
			{
				Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::FORWARD);
				m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			}

			if (m_colhandler->ItemWasHit())
			{
				if (m_difficulty > 0.12f)
				{
					m_difficulty -= 0.01f;
				}
				else if (m_difficulty > 0.032f)
				{
					m_difficulty -= 0.002f;
				}
				std::printf("%.5f\n", m_difficulty);
			}
			m_timesteps = 0;
		}
	}
	else
	{
		if (m_keys[Keys::W])
		{
			m_pausemenu[(1 + m_operatemenu)].setFillColor(sf::Color(102, 102, 51));
			m_operatemenu = !m_operatemenu;
			m_pausemenu[(1 + m_operatemenu)].setFillColor(sf::Color::White);
			m_keys[Keys::W] = false;
		}
		else if (m_keys[Keys::S])
		{
			m_pausemenu[(1 + m_operatemenu)].setFillColor(sf::Color(102, 102, 51));
			m_operatemenu = !m_operatemenu;
			m_pausemenu[(1 + m_operatemenu)].setFillColor(sf::Color::White);
			m_keys[Keys::S] = false;
		}
		else if (m_keys[Keys::ENTER])
		{
			if (m_pausemenu[2].getFillColor() == sf::Color::White)
			{
				return 1;
			}
			m_keys[Keys::ENTER] = false;
		}
	}

	return 0;
}

void Game::Shutdown()
{
	if (m_mapholder)
	{
		delete m_mapholder;
		m_mapholder = nullptr;
	}
	if (m_itemholder)
	{
		delete m_itemholder;
		m_itemholder = nullptr;
	}
	if (m_snakeholder)
	{
		delete m_snakeholder;
		m_snakeholder = nullptr;
	}
	if (m_colhandler)
	{
		delete m_colhandler;
		m_colhandler = nullptr;
	}
	if (m_notifier)
	{
		delete m_notifier;
		m_notifier = nullptr;
	}
	for (int i = 0; i < 3; i++)
	{
		m_pausemenu[i].setOutlineThickness(0);
		m_pausemenu[i].setOutlineColor(sf::Color());
	}
}

void Game::setFileHandler(FileHandler * fh)
{
	filehandler = fh;
}

int Game::getHighScore() const
{
	return m_score;
}

void Game::HandleInput(const sf::Event &e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		Snake::MovedPieces a;
		switch (e.key.code)
		{
		case sf::Keyboard::A:
			m_keys[Keys::A] = true;
			m_keys[Keys::D] = false;
			break;
		case sf::Keyboard::D:
			m_keys[Keys::D] = true;
			m_keys[Keys::A] = false;
			break;
		case sf::Keyboard::T:
			m_keys[Keys::PAUSE] = !m_keys[Keys::PAUSE];
			break;
		case sf::Keyboard::W:
			if (m_keys[Keys::PAUSE])
				m_keys[Keys::W] = true;
			break;
		case sf::Keyboard::S:
			if (m_keys[Keys::PAUSE])
				m_keys[Keys::S] = true;
			break;
		case sf::Keyboard::Return:
			if (m_keys[Keys::PAUSE])
				m_keys[Keys::ENTER] = true;
			break;
		//case sf::Keyboard::Q://TEST
		//	std::printf("\nE: RESPAWN ITEM\n");
		//	m_itemholder->Respawn(m_colhandler->UpdateItem());
		//	break;
		//case sf::Keyboard::E://TEST
		//	std::printf("\nE: ADD PIECE\n");
		//	// Add a snake piece
		//	m_snakeholder->Add();
		//	break;
		case sf::Keyboard::P://TEST
			system("cls");
			//TEST - Print out collision map
			m_colhandler->Print();
			break;
		default:
			std::printf("%d", e.key.code);
			break;
		}
	}
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (!m_keys[Keys::PAUSE])
		target.draw(m_backsprite, states);
	if (m_mapholder)
		target.draw(*m_mapholder, states);
	if (m_itemholder)
		target.draw(*m_itemholder, states);
	if (m_snakeholder)
		target.draw(*m_snakeholder, states);
	if (m_keys[Keys::PAUSE])
	{
		target.draw(m_backsprite, states);
		target.draw(m_pausemenu[0], states);
		target.draw(m_pausemenu[1], states);
		target.draw(m_pausemenu[2], states);
	}
}