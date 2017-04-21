#include <Amadeus\ItemHolder.h>
ItemHolder::ItemHolder()
{
	m_items = nullptr;
}
ItemHolder::~ItemHolder()
{
	Shutdown();
}

int ItemHolder::Init()
{
	Shutdown();
	m_activeitem = 0;
	m_numitems = 7;
	m_items = new Item[m_numitems];
	for (int i = 0; i < m_numitems; i++)
	{
		m_items[i].Init(sf::Vector2i((3 * i) + 3, (3 * i) + 3), i + 1);
	}
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
/**
*	Active item returns it's position on the grid map
*/
sf::Vector2i ItemHolder::getActiveItemPos() const
{
	return m_items[m_activeitem].getGridPos();
}

int ItemHolder::getPoints() const
{
	return m_items[m_activeitem].getPoints();
}

void ItemHolder::Shutdown()
{
	if (m_items)
	{
		delete[] m_items;
		m_items = nullptr;
	}
}

void ItemHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numitems; i++)
	{
		target.draw(m_items[i], states);
	}
	//target.draw(m_items[m_activeitem], states);
}
