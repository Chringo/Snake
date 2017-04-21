#include <Amadeus\SnakeHolder.h>
SnakeHolder::SnakeHolder()
{

}
SnakeHolder::~SnakeHolder()
{
	Shutdown();
}

void SnakeHolder::Init(sf::Vector2i startpos)
{
	Shutdown();

}

sf::Vector2i SnakeHolder::Move(int direction, int input)
{
	return sf::Vector2i();
}

void SnakeHolder::Shutdown()
{

}

void SnakeHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}
