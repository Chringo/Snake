#include <Amadeus\Game.h>
Game::Game()
{
	m_score = 0;
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
	m_mapholder->Init(map, HEIGHT, WIDTH);

	m_itemholder = new ItemHolder();
	m_itemholder->Init();
	for (int i = 0; i < 7; i++)//TEST
	{
		sf::Vector2i temp = m_itemholder->getActiveItemPos();
		map[temp.x * HEIGHT + temp.y] = 2;
	}

	m_snakeholder = new SnakeHolder();
	m_snakeholder->Init(sf::Vector2i((WIDTH / 2) + 1, HEIGHT / 2));
	for (int i = 0; i < 4; i++)//TEST
	{
		map[(HEIGHT / 2) * HEIGHT + (WIDTH / 2) + 1 + i] = 3;
	}

	m_notifier = new Notifier();
	m_notifier->Init(m_snakeholder, m_itemholder);

	m_colhandler = new CollisionHandler();
	m_colhandler->Init(m_notifier, map, HEIGHT, WIDTH);

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
	//std::printf("%.6f\n", dt);//TEST
	m_colhandler->UpdateItem(m_itemholder->getActiveItemPos());
	if (m_notifier->getLost())
	{
		this->Init();
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
		case sf::Keyboard::S:
			a = m_snakeholder->Move(0);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			break;
		case sf::Keyboard::W:
			a = m_snakeholder->Move(1);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			break;
		case sf::Keyboard::A:
			a = m_snakeholder->Move(2);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			break;
		case sf::Keyboard::D:
			a = m_snakeholder->Move(3);
			m_colhandler->UpdateSnake(a.mp_front, a.mp_back);
			break;
		case sf::Keyboard::Q://TEST
			std::printf("\nE: RESPAWN ITEM\n");
			m_itemholder->Respawn();
			break;
		case sf::Keyboard::E://TEST
			std::printf("\nE: ADD PIECE\n");
			// Add a snake piece
			m_snakeholder->Add();
			break;
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