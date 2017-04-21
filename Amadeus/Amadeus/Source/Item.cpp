#include <Amadeus\Item.h>
Item::Item() {}
Item::~Item() {}

void Item::Init(sf::Vector2i gridpos, int points)
{
	m_gridpos = gridpos;
	m_points = points;

	float size = 18;
	shape = sf::CircleShape(size / 2);
	shape.setPosition(5 + 3 + m_gridpos.x * 25, 5 + 3 + m_gridpos.y * 25);
	shape.setFillColor(sf::Color((35 * m_points), (35 * m_points), 125));
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);
}

sf::Vector2i Item::getGridPos() const
{
	return m_gridpos;
}

int Item::getPoints() const
{
	return m_points;
}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(m_sprite, states);
	target.draw(shape, states);
}