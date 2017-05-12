#include <Amadeus\Item.h>
Item::Item() {}
Item::~Item() {}

void Item::Init(int points)
{
	m_gridpos = sf::Vector2i();
	m_points = points;

	float size = sDrawSize - 6;
	shape = sf::CircleShape(size / 2);
	shape.setPosition(5 + 3 + m_gridpos.x * (sDrawSize + 1), 5 + 3 + m_gridpos.y * (sDrawSize + 1));
	shape.setFillColor(sf::Color((35 * m_points), (35 * m_points), 125));
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);
}

void Item::setGridPos(const int x, const int y)
{
	m_gridpos = sf::Vector2i(x, y);
	shape.setPosition(5 + 3 + x * (sDrawSize + 1), 5 + 3 + y * (sDrawSize + 1));
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