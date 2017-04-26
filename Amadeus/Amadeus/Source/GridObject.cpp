#include <Amadeus\GridObject.h>
GridObject::GridObject()
{
}
GridObject::~GridObject()
{
}

void GridObject::setGridPos(sf::Vector2i newpos)
{
	m_gridpos = newpos;
}

sf::Vector2i GridObject::getGridPos() const
{
	return m_gridpos;
}
