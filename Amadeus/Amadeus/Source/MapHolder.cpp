#include <Amadeus\MapHolder.h>
MapHolder::MapHolder()
{
	m_map = nullptr;
	m_numtiles = 0;
}
MapHolder::~MapHolder()
{
	Shutdown();
}

int MapHolder::Init(const int HEIGHT, const int WIDTH, int ** map)
{
	Shutdown();
	m_numtiles = HEIGHT * WIDTH;
	m_map = new Tile[m_numtiles];
	for (int h = 0; h < HEIGHT; h++)
	{
		for (int w = 0; w < WIDTH; w++)
		{
			m_map[h * HEIGHT + w].Init(map[h * HEIGHT + w], h, w);
		}
	}
	return 0;
}

void MapHolder::Shutdown()
{
	if (m_map)
	{
		delete[] m_map;
		m_map = nullptr;
	}
}

void MapHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numtiles; i++)
	{
		target.draw(m_map[i], states);
	}
}