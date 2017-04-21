#include <Amadeus\Item.h>
Item::Item() {}
Item::~Item() {}

int Item::getPoints() const
{
	return m_points;
}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(m_sprite, states);
	target.draw(shape, states);
}