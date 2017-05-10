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
	m_direction = 1;// Forward
	m_snake = new Snake();
	m_snake->Init(startpos);
	return 0;
}

Snake::MovedPieces SnakeHolder::Move(KeyInput input)
{
	if (input == KeyInput::LEFT)
	{
		if (m_direction == 3)
			m_direction = 0;
		else
			m_direction++;
	}
	else if (input == KeyInput::RIGHT)
	{
		if (m_direction == 0)
			m_direction = 3;
		else
			m_direction--;
	}

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
