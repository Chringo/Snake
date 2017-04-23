#include <Amadeus\Snake.h>
Snake::Snake()
{
	m_pieces = nullptr;
}
Snake::~Snake()
{
	Shutdown();
}

void Snake::Init(sf::Vector2i gridpos)
{
	Shutdown();
	m_numpieces = 4;
	m_pieces = new SnakePiece[m_numpieces];
	sf::Vector2i gp = gridpos;
	for (int i = 0; i < m_numpieces; i++)
	{
		m_pieces[i].Init(gp, SnakePiece::Body);
		gp.x++;
	}
}

void Snake::Increase(int amount)
{
}

void Snake::Decrease(int amount)
{
}

void Snake::Reset()
{
}

void Snake::Shutdown()
{
	// TODO - Replace Shutdown by allocating memory for future pieces of the snake.
	if (m_pieces)
	{
		delete[] m_pieces;
		m_pieces = nullptr;
	}
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numpieces; i++)
	{
		target.draw(m_pieces[i], states);
	}
}
