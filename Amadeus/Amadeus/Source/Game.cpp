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
	m_score = 0;
	m_mapholder = new MapHolder();
	// TODO - Import map
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
	m_mapholder->Init(&map[0], HEIGHT, WIDTH);

	m_itemholder = new ItemHolder();
	m_itemholder->Init();
	for (int i = 0; i < 7; i++)//TEST
	{
		sf::Vector2i temp = m_itemholder->getActiveItemPos();
		map[temp.x * HEIGHT + temp.y] = 2;
	}

	m_snakeholder = new SnakeHolder();
	m_snakeholder->Init(sf::Vector2i((WIDTH / 2) + 1, HEIGHT / 2));
	for (int i = 0; i < 6; i++)//TEST
	{
		map[(HEIGHT / 2) * HEIGHT + (WIDTH / 2) + 1 + i] = 3;
	}

	//TEST - Print out potential collision map
	for (int h = 0; h < HEIGHT; h++)//TEST
	{
		for (int w = 0; w < WIDTH; w++)
		{
			std::printf("%d ", map[h * HEIGHT + w]);
		}
		std::printf("\n");
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
	//std::printf("%.6f\n", dt);//TEST
	//HandleInput(e);

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
}

int Game::getHighScore() const
{
	return m_score;
}

void Game::HandleInput(const sf::Event &e)
{
	// TODO - See if we even need "const sf::Event &e".
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_snakeholder->Move(0, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_snakeholder->Move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_snakeholder->Move(2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_snakeholder->Move(3, 0);
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