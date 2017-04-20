#include <Amadeus\MapHolder.h>

MapHolder::MapHolder()
{
	m_map = nullptr;
}


MapHolder::~MapHolder()
{
	if (m_map)
	{
		delete[] m_map;
		m_map = nullptr;
	}
}

int MapHolder::Init(int  *map, int size)
{
	m_numtiles = size * size;
	for (int h = 0; h < size; h++)//TEST
	{
		for (int w = 0; w < size; w++)
		{
			std::printf("%d ", map[h * size + w]);
		}
		std::printf("\n");
	}
	m_map = new Tile[m_numtiles];
	for (int h = 0; h < size; h++)
	{
		for (int w = 0; w < size; w++)
		{
			m_map[h * size + w].Init(map[h * size + w], h, w);
		}
	}
	return 0;
}

void MapHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numtiles; i++)
	{
		target.draw(m_map[i], states);
	}
}