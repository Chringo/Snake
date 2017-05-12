#include <Amadeus\GridObject.h>
const float GridObject::sDrawSize = 26.0f;
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
