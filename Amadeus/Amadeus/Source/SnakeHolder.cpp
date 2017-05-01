#include <Amadeus\SnakeHolder.h>
SnakeHolder::SnakeHolder()
{
	m_snake = nullptr;
}
SnakeHolder::~SnakeHolder()
{
	Shutdown();
}

int SnakeHolder::Init(sf::Vector2i startpos)
{
	Shutdown();
	m_snake = new Snake();
	m_snake->Init(startpos);
	return 0;
}

Snake::MovedPieces SnakeHolder::Move(int direction, int input)
{
	return m_snake->Move(direction);
}

void SnakeHolder::Shutdown()
{
	if (m_snake)
	{
		delete m_snake;
		m_snake = nullptr;
	}
}

void SnakeHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_snake, states);
}
