#include <Amadeus\ItemHolder.h>
ItemHolder::ItemHolder()
{
	m_items = nullptr;
}
ItemHolder::~ItemHolder()
{
	Shutdown();
}

int ItemHolder::Init(int *map, const int HEIGHT, const int WIDTH)
{
	Shutdown();
	m_activeitem = 1;
	m_numitems = 7;
	m_items = new Item[m_numitems];

	std::random_device rd;// Obtain a new seed for each game instance, hence why it's local
	gen = std::mt19937(rd());// Load seed into generator
	// TODO - If map design can be intact, split the map in four parts to even out the pseudo-RNG
	disx = std::uniform_int_distribution<int>(1, WIDTH - 2);//TEST
	disy = std::uniform_int_distribution<int>(1, HEIGHT - 2);//1, WIDTH-2, etc - replaced with fileloading

	for (int i = 0; i < m_numitems; i++)//TEST
	{
		m_items[i].Init(sf::Vector2i(disx(gen), disy(gen)), i + 1);
	}

	sf::Vector2i temp = this->getActiveItemPos();
	map[temp.x * HEIGHT + temp.y] = 2;
	return 0;
}

int ItemHolder::Respawn()
{
	// Move current item
	m_items[m_activeitem].setGridPos(disx(gen), disy(gen));
	// Set new active item
	if (m_activeitem == m_numitems - 1)
		m_activeitem = 0;
	else
		m_activeitem++;
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
	for (int i = 0; i < m_numitems; i++)//TEST
	{
		target.draw(m_items[i], states);
	}
	//target.draw(m_items[m_activeitem], states);
}
