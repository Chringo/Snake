#ifndef AMADEUS_MAIN_SNAKEPIECE_H_
#define AMADEUS_MAIN_SNAKEPIECE_H_
#include <Amadeus\GridObject.h>
class SnakePiece : public GridObject
{
public:
	enum Piece : unsigned int
	{
		Body = 1,
		Head,
		Tail
	};

	SnakePiece();
	~SnakePiece();


	void Init(sf::Vector2i gridpos, Piece type);
	void setType(Piece type);
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::CircleShape shape;//TEST	
	Piece m_type;
};
#endif // AMADEUS_MAIN_SNAKEPIECE_H_