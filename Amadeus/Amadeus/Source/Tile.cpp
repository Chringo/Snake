#include <Amadeus\Tile.h>
Tile::Tile() 
{
	m_iswall = false;
}
Tile::~Tile() {}

void Tile::Init(int type, int height, int width)
{
	float size = sDrawSize;
	shape = sf::RectangleShape(sf::Vector2f(size, size));
	shape.setPosition(5 + width * (sDrawSize + 1), 5 + height * (sDrawSize + 1));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color::White);
	if (type == 0)// TODO - Add enum class
	{
		shape.setFillColor(sf::Color(50, 75, 25));
		m_iswall = false;
	}
	else
	{
		shape.setFillColor(sf::Color(50, 0, 25));
		m_iswall = true;
	}
	m_gridpos = sf::Vector2i(width, height);
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
