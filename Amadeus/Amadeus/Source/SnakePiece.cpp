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
	float size = 20;
	shape = sf::CircleShape(size / 2, 4);
	shape.setPosition(5 + 2 + m_gridpos.x * 25.0f, 5 + 2 + m_gridpos.y * 25.0f);
	shape.setFillColor(sf::Color::Black);
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
