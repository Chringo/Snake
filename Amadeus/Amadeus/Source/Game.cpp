#include <Amadeus\Game.h>

Game::Game() 
{
	m_mapholder = nullptr;
}
Game::~Game() {}

int Game::Init()
{
	m_score = 0;
	m_mapholder = new MapHolder();

	// TODO - Import map
	// Generate map
	const int MAPSIZE = 16;
	int map[MAPSIZE*MAPSIZE];
	for (int h = 0; h < MAPSIZE; h++)
	{
		for (int w = 0; w < MAPSIZE; w++)
		{
			if(h == 0)
				map[h * MAPSIZE + w] = 1;
			else if (h == MAPSIZE - 1)
				map[h * MAPSIZE + w] = 1;
			else if (w == 0)
				map[h * MAPSIZE + w] = 1;
			else if (w == MAPSIZE - 1)
				map[h * MAPSIZE + w] = 1;
			else
				map[h * MAPSIZE + w] = 0;
		}
	}
	m_mapholder->Init(&map[0], MAPSIZE);

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

	sf::CircleShape shape(100.f);//TEST
	shape.setFillColor(sf::Color::Green);
	target.draw(shape, states);
}