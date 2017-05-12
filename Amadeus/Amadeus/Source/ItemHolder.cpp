#include <Amadeus\ItemHolder.h>
ItemHolder::ItemHolder()
{
	m_items = nullptr;
}
ItemHolder::~ItemHolder()
{
	Shutdown();
}

int ItemHolder::Init(int numitems, int startingpointvalue)
{
	Shutdown();
	m_numitems = numitems;
	m_items = new Item[m_numitems];
	for (int i = 0; i < m_numitems; i++)
	{
		m_items[i].Init(i + startingpointvalue);
	}
	m_activeitem = 0;
	return 0;
}

int ItemHolder::Respawn(sf::Vector2i pos)
{
	// Set new active item
	if (m_activeitem == m_numitems - 1)
		m_activeitem = 0;
	else
		m_activeitem++;
	// Move current item
	m_items[m_activeitem].setGridPos(pos.x, pos.y);
	return 0;
}
int ItemHolder::UpdateScore()//TEST int for debug output
{
	m_currentscore += this->getPoints();
	return m_currentscore;
}
int ItemHolder::getHighScore() const
{
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
