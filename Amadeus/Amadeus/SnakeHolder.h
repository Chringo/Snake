#ifndef AMADEUS_MAIN_SNAKEHOLDER_H_
#define AMADEUS_MAIN_SNAKEHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Snake.h>
class SnakeHolder : public sf::Drawable
{
public:
	SnakeHolder();
	~SnakeHolder();

	int Init(sf::Vector2i startpos);
	Snake::MovedPieces Move(int input);
	void Add();
private:
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int m_direction;
	Snake *m_snake;
};
#endif // AMADEUS_MAIN_SNAKEHOLDER_H_
