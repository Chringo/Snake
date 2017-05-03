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
	m_activeitem = 1;
	m_numitems = 7;
	m_items = new Item[m_numitems];
	for (int i = 0; i < m_numitems; i++)
	{
		m_items[i].Init(sf::Vector2i((2 * i) + 1, (2 * i) + 1), i + 1);
	}
	return 0;
}

int ItemHolder::Respawn()
{
	// Remove current item
	// TODO - Should we remove something?
	// Move current item
	// TODO
	// Set new active item
	if (m_activeitem == m_numitems - 1)
		m_activeitem = 0;
	else
		m_activeitem++;
	// Should we return points from here?
	// Might break responsibility of function
	return 0;
}
int ItemHolder::UpdateScore()//TEST int for debug output
{
	m_currentscore += this->getPoints();
	return m_currentscore;
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
	//for (int i = 0; i < m_numitems; i++)//TEST
	//{
	//	target.draw(m_items[i], states);
	//}
	target.draw(m_items[m_activeitem], states);
}
