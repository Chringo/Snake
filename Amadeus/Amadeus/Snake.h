#ifndef AMADEUS_MAIN_SNAKE_H_
#define AMADEUS_MAIN_SNAKE_H_
#include <vector>
#include <SFML\Graphics.hpp>
#include <Amadeus\SnakePiece.h>
class Snake : public sf::Drawable
{
public:
	Snake();
	~Snake();

	void Init(sf::Vector2i gridpos);
	void Increase(int amount = 1);
	void Decrease(int amount = 1);
	void Reset();
private:
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	std::vector<SnakePiece*> m_pieces;
	int m_numpieces;
};
#endif // AMADEUS_MAIN_SNAKE_H_