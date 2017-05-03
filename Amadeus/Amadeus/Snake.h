#ifndef AMADEUS_MAIN_SNAKE_H_
#define AMADEUS_MAIN_SNAKE_H_
#include <vector>
#include <SFML\Graphics.hpp>
#include <Amadeus\SnakePiece.h>
class Snake : public sf::Drawable
{
public:
/// Member variables of structs starts with <*_> and are lowercase.
/// <*> represents the capital letters of the struct name.
	struct MovedPieces
	{
		sf::Vector2i mp_front;
		sf::Vector2i mp_back;
	};
	Snake();
	~Snake();

	void Init(sf::Vector2i gridpos);
	void Increase(int amount = 1);
	void Decrease(int amount = 1);
	void Reset();
	MovedPieces Move(int direction);
private:
	void Swap(SnakePiece &current, SnakePiece &target);
	void Swap(SnakePiece *&current, SnakePiece *&target);
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	std::vector<SnakePiece*> m_pieces;
	int m_numpieces;
	int m_maxpieces;
	int m_backindex;
	SnakePiece *m_front;
	SnakePiece *m_back;
	MovedPieces m_moved;
};
#endif // AMADEUS_MAIN_SNAKE_H_