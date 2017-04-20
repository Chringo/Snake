#include <Amadeus\Tile.h>
Tile::Tile() {}
Tile::~Tile() {}

void Tile::Init(int type, int height, int width)
{
	float size = 30;
	shape = sf::RectangleShape(sf::Vector2f(size, size));
	shape.setPosition(5 + height * (size + 1), 5 + width * (size + 1));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color::White);
	if (type == 0)// TODO - Add static enum
	{
		shape.setFillColor(sf::Color(50, 75, 25));
		m_iswall = false;
	}
	else
	{
		shape.setFillColor(sf::Color(50, 0, 25));
		m_iswall = true;
	}
}

bool Tile::isWall() const
{
	return m_iswall;
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(m_sprite, states);
	target.draw(shape, states);
}
