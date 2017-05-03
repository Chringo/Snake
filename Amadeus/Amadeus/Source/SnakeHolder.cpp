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

Snake::MovedPieces SnakeHolder::Move(int input)
{
	if (0 <= input && input <= 3)
		m_direction = input;
	else
		m_direction = -1;
	return m_snake->Move(m_direction);
}

void SnakeHolder::Add()
{
	m_snake->Increase();
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
