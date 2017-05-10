#include <Amadeus\Snake.h>
#define STARTING_SNAKE_SIZE 4
Snake::Snake()
{
	m_maxpieces = 16;
	m_numpieces = STARTING_SNAKE_SIZE;
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
	if (m_numpieces == m_maxpieces)
	{
		m_maxpieces = m_maxpieces * 2;
		for (int i = m_numpieces; i < m_maxpieces; i++)
		{
			m_pieces.push_back(new SnakePiece());
		}
	}
	int i = m_numpieces;
	for (i; i >  m_backindex + 1; i--)
	{
		Swap(m_pieces[i], m_pieces[i - 1]);
	}
	m_pieces[i]->Init(m_pieces[m_backindex]->getGridPos(), SnakePiece::Body);
	m_backindex++;
	m_back = m_pieces[m_backindex];
	m_numpieces++;
}

void Snake::Decrease(int amount)
{
}

void Snake::Reset()
{
	if (!m_pieces.empty())
	{
		m_maxpieces = 16;
		m_numpieces = STARTING_SNAKE_SIZE;
		for (int i = (int)m_pieces.size() - 1; i >= m_maxpieces; i--)
		{
			delete m_pieces[i];
			m_pieces[i] = nullptr;
		}
		m_pieces.resize(m_maxpieces);
	}
}

Snake::MovedPieces Snake::Move(int direction)
{
	sf::Vector2i gp = m_front->getGridPos();
	switch (direction)
	{
	case 0://UP
		gp.y--;
		break;
	case 1://LEFT
		gp.x--;
		break;
	case 2://DOWN
		gp.y++;
		break;
	case 3://RIGHT
		gp.x++;
		break;
	default://Failure
		gp = sf::Vector2i(0, 0);
		break;
	}
	m_moved.mp_front = gp;
	m_moved.mp_back = m_back->getGridPos();
	m_back->setGridPos(gp);
	m_back->Test();//TEST Update graphical position which is stored in SnakePiece and not GridObject
	m_front = m_back;
	if (m_backindex > 0)
		m_backindex--;
	else
		m_backindex = m_numpieces - 1;
	m_back = m_pieces[m_backindex];
	return m_moved;
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
