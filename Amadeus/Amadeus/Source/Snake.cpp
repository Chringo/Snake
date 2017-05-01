#include <Amadeus\Snake.h>
Snake::Snake()
{
	m_maxpieces = 16;
	m_numpieces = 4;
	for (int i = 0; i < m_maxpieces; i++)
	{
		m_pieces.push_back(new SnakePiece());
	}
}
Snake::~Snake()
{
	Shutdown();
	if (!m_pieces.empty())
	{
		for (int i = 0; i < m_pieces.size(); i++)
		{
			delete m_pieces[i];
		}
		m_pieces.clear();
	}
}

void Snake::Init(sf::Vector2i gridpos)
{
	Reset();
	sf::Vector2i gp = gridpos;
	for (int i = 0; i < m_numpieces; i++)
	{
		m_pieces[i]->Init(gp, SnakePiece::Body);
		gp.x++;
	}
	m_backindex = m_numpieces - 1;
	m_front = m_pieces[0];
	m_back = m_pieces[m_backindex];
}

void Snake::Increase(int amount)
{
	//TEST
	sf::Vector2i gp = m_pieces.back()->getGridPos();
	gp.x++;
	m_pieces.push_back(new SnakePiece());
	m_pieces.back()->Init(gp, SnakePiece::Body);
}

void Snake::Decrease(int amount)
{
}

void Snake::Reset()
{
	if (!m_pieces.empty())
	{
		m_maxpieces = 16;
		m_numpieces = 4;
		for (int i = (int)m_pieces.size() - 1; i >= m_maxpieces; i--)
		{
			delete m_pieces[i];
		}
		// TODO - Test for proper shrinkage
		// m_pieces.size() == m_maxpieces 
		m_pieces.shrink_to_fit();
	}
}

sf::Vector2i Snake::Move(int direction)
{
	sf::Vector2i gp = m_front->getGridPos();
	switch (direction)
	{
	case 0://DOWN
		gp.y++;
		break;
	case 1://UP
		gp.y--;
		break;
	case 2://LEFT
		gp.x--;
		break;
	case 3://RIGHT
		gp.x++;
		break;
	default://Failure
		gp = sf::Vector2i(0, 0);
		break;
	}
	m_back->setGridPos(gp);
	m_back->Test();
	m_front = m_back;
	m_backindex--;
	m_back = m_pieces[m_backindex];
	//m_front->Test();//Only back needs to get updated since we're only handling bodies for now
	return gp;
}
/**
*	Swap the variables in the objects.
*/
void Snake::Swap(SnakePiece &current, SnakePiece &target)
{
	SnakePiece temp = target;
	target = current;
	current = temp;
}
/**
*	Swap the addresses the pointers are pointing to.
*/
void Snake::Swap(SnakePiece *&current, SnakePiece *&target)
{
	SnakePiece *temp = target;
	target = current;
	current = temp;
}

void Snake::Shutdown()
{
	
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < m_numpieces; i++)
	{
		target.draw(*m_pieces[i], states);
	}
}
