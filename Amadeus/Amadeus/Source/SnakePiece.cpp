#include <Amadeus\SnakePiece.h>
SnakePiece::SnakePiece()
{
}
SnakePiece::~SnakePiece()
{
}

void SnakePiece::operator=(const SnakePiece &orig)
{
	//Init(orig.m_gridpos, orig.m_type);
	this->m_gridpos = orig.m_gridpos;
	this->m_type = orig.m_type;

	this->shape = orig.shape;
	this->m_texture = orig.m_texture;
	this->m_sprite = orig.m_sprite;
}

void SnakePiece::Init(sf::Vector2i gridpos, Piece type)
{
	m_gridpos = gridpos;
	m_type = Piece::Body;
	float size = m_size - 4;
	shape = sf::CircleShape(size / 2, 4);
	shape.setPosition(5 + 2 + m_gridpos.x * (m_size + 1), 5 + 2 + m_gridpos.y * (m_size + 1));
	sf::Uint8 test = 9;//TEST
	shape.setFillColor(sf::Color((test * m_gridpos.x), 0, (test * m_gridpos.x)));
}

void SnakePiece::Test()
{
	shape.setPosition(5 + 2 + m_gridpos.x * (m_size + 1), 5 + 2 + m_gridpos.y * (m_size + 1));
}

void SnakePiece::setType(Piece type)
{
	m_type = type;
	// TODO - If we change type we need to reshape accordingly.
}

void SnakePiece::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(m_sprite, states);
	target.draw(shape, states);
}
