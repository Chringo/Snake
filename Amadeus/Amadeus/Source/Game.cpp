#include <Amadeus\Game.h>
Game::Game()
{
	m_mapholder = nullptr;
	m_itemholder = nullptr;
}
Game::~Game() {}

int Game::Init()
{
	m_score = 0;
	m_mapholder = new MapHolder();

	// TODO - Import map
	// Generate map - Only quadratic map works for now
	const int HEIGHT = 25;
	const int WIDTH = HEIGHT;
	int map[HEIGHT*WIDTH];
	for (int h = 0; h < HEIGHT; h++)
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
}

int Game::getHighScore() const
{
	return m_score;
}

void Game::HandleInput(const sf::Event &e)
{

}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(m_backsprite, states);
	if (m_mapholder)
		target.draw(*m_mapholder, states);
	if (m_itemholder)
		target.draw(*m_itemholder, states);
}