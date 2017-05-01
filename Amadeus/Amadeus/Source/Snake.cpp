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
		for (int i = m_pieces.size() - 1; i >= m_maxpieces; i--)
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
	sf::Vector2i gp = m_pieces[0]->getGridPos();
	switch (direction)
	{
	case 0://Up
		gp.y++;
		break;
	case 1://Down
		gp.y--;
		break;
	case 2://Left
		gp.x--;
		break;
	case 3://Right
		gp.x++;
		break;
	default://Failure
		gp = sf::Vector2i(0, 0);
		break;
	}
	Swap(*m_pieces[1], *m_pieces[3]);
	return gp;
}

void Snake::Swap(SnakePiece &current, SnakePiece &target)
{
	SnakePiece temp = target;
	target = current;
	current = temp;
	sf::Vector2i test = current.getGridPos();//TEST
	test.y++;
	current.setGridPos(test);
	test = target.getGridPos();//TEST
	test.y++;
	target.setGridPos(test);
	current.Test();
	target.Test();
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
