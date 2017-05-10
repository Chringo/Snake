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
	m_difficulty = 0.5f;
	m_mapholder = new MapHolder();
	// TODO - Import map
	const int HEIGHT = 15;
	const int WIDTH = HEIGHT;
	int map[HEIGHT * WIDTH];
	// Generate map - Only quadratic map works for now
	for (int h = 0; h < HEIGHT; h++)//TEST
	{
		for (int w = 0; w < WIDTH; w++)
		{
			if (h == 0)
				map[h * HEIGHT + w] = 1;
			else if (h == HEIGHT - 1)
				map[h * HEIGHT + w] = 1;
			else if (w == 0)
				map[h * HEIGHT + w] = 1;
			else if (w == WIDTH - 1)
				map[h * HEIGHT + w] = 1;
			else
				map[h * HEIGHT + w] = 0;
		}
	}
	m_mapholder->Init(HEIGHT, WIDTH, map);

	m_snakeholder = new SnakeHolder();
	m_snakeholder->Init(sf::Vector2i((WIDTH / 2), HEIGHT / 2));
	for (int i = 0; i < 4; i++)//TEST
	{
		map[(HEIGHT / 2) * HEIGHT + (WIDTH / 2) + i] = 3;
	}

	m_itemholder = new ItemHolder();
	m_itemholder->Init(HEIGHT, WIDTH, map);

	m_notifier = new Notifier();
	m_colhandler = new CollisionHandler();
	m_notifier->Init(m_snakeholder, m_itemholder, m_colhandler);
	m_colhandler->Init(m_notifier, map, HEIGHT, WIDTH);

	m_itemholder->Respawn(m_colhandler->getRandomPos());
	m_colhandler->UpdateItem(m_itemholder->getActiveItemPos());

	for (int i = 0; i < Keys::SIZE; i++)
	{
		m_keys.push_back(false);
	}
	// Background
	//if (m_backtexture.loadFromFile("../Assets/Textures/bgd_wood.png"))
	//{
	//	m_backsprite.setTexture(m_backtexture);
	//	m_backsprite.setColor(sf::Color(50, 50, 50, 255));
	//}
	return 0;
}

int Game::Update(const sf::Event &e, float dt)
{
	m_gametime += dt;
	m_timesteps += dt;
	//std::printf("%.6f\n", dt);//TEST
	if (m_notifier->getLost())
	{
		std::printf("FINAL SCORE: %d\n", m_itemholder->getHighScore());
		this->Init();
	}

	if (m_timesteps > m_difficulty)
	{
		//std::printf("%.6f\n", m_gametime);//TEST
		if (m_keys[Keys::A])
		{
			Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::LEFT);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			m_keys[Keys::A] = false;
		}
		else if(m_keys[Keys::D])
		{
			Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::RIGHT);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			m_keys[Keys::D] = false;
		}
		else// Forward
		{
			Snake::MovedPieces a = m_snakeholder->Move(SnakeHolder::KeyInput::FORWARD);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
		}
		m_timesteps = 0;
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
	m_keys.clear();
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
			//std::printf("PREPARE LEFT\n");//TEST
			m_keys[Keys::A] = true;
			m_keys[Keys::D] = false;
			break;
		case sf::Keyboard::D:
			//std::printf("PREPARE RIGHT\n");//TEST
			m_keys[Keys::D] = true;
			m_keys[Keys::A] = false;
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
	//target.draw(m_backsprite, states);
	if (m_mapholder)
		target.draw(*m_mapholder, states);
	if (m_itemholder)
		target.draw(*m_itemholder, states);
	if (m_snakeholder)
		target.draw(*m_snakeholder, states);
}