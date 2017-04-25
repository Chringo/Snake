#include <Amadeus\Snake.h>
Snake::Snake()
{
}
Snake::~Snake()
{
	Shutdown();
}

void Snake::Init(sf::Vector2i gridpos)
{
	Shutdown();
	m_numpieces = 4;
	sf::Vector2i gp = gridpos;
	for (int i = 0; i < m_numpieces; i++)
	{
		m_pieces.push_back(SnakePiece());
		m_pieces[i].Init(gp, SnakePiece::Body);
		gp.x++;
	}
}

void Snake::Increase(int amount)
{
	//TEST
	sf::Vector2i gp = m_pieces.back().getGridPos();
	gp.x++;
	m_pieces.push_back(SnakePiece());
	m_pieces.back().Init(gp, SnakePiece::Body);
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
	if (!m_pieces.empty())
	{

		m_pieces.clear();
	}
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numpieces; i++)
	{
		target.draw(m_pieces[i], states);
	}
}
