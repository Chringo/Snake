#include <Amadeus\ItemHolder.h>

ItemHolder::ItemHolder()
{
}
ItemHolder::~ItemHolder()
{
}

int ItemHolder::Init()
{
	// Initialise finite set of items
	return 0;
}

int ItemHolder::Respawn()
{
	// Remove current item
	// Set new active item
	// Move active item
	// Should we return something?
	return 0;
}

sf::Vector2i ItemHolder::getPos() const
{
	// Return active item's position from list
	return sf::Vector2i();
}

int ItemHolder::getPoints() const
{
	// Return the active item's points 
	return 0;
}

void ItemHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// Draw active item(s)
}
