#include <Amadeus\GridObject.h>
GridObject::GridObject()
{
}
GridObject::~GridObject()
{
}

sf::Vector2i GridObject::getGridPos() const
{
	return m_gridpos;
}
