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

int MapHolder::Init(int  *map, int height, int width)
{
	Shutdown();
	m_numtiles = height * width;
	m_map = new Tile[m_numtiles];
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			m_map[h * height + w].Init(map[h * height + w], h, w);
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