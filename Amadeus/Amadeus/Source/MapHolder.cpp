#include <Amadeus\MapHolder.h>
MapHolder::MapHolder()
{
	m_map = nullptr;
	m_height = 0;
	m_width = 0;
}
MapHolder::~MapHolder()
{
	Shutdown();
}

int MapHolder::Init(const int HEIGHT, const int WIDTH, int ** map)
{
	Shutdown();
	m_height = HEIGHT;
	m_width = WIDTH;
	m_map = new Tile*[m_height];
	for (int h = 0; h < m_height; h++)
	{
		m_map[h] = new Tile[m_width];
		for (int w = 0; w < m_width; w++)
		{
			m_map[h][w].Init(map[h][w], h, w);
		}
	}
	return 0;
}

void MapHolder::Shutdown()
{
	if (m_map)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_map[i];
		}
		delete m_map;
		m_map = nullptr;
	}
}

void MapHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int h = 0; h < m_height; h++)
	{
		for (int w = 0; w < m_width; w++)
		{
			target.draw(m_map[h][w], states);
		}
	}
}