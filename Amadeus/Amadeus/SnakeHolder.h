#ifndef AMADEUS_MAIN_SNAKEHOLDER_H_
#define AMADEUS_MAIN_SNAKEHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Snake.h>
class SnakeHolder : public sf::Drawable
{
public:
	SnakeHolder();
	~SnakeHolder();

	void Init(sf::Vector2i startpos);
	sf::Vector2i Move(int direction, int input);
private:
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	Snake *m_snake;
};
#endif // AMADEUS_MAIN_SNAKEHOLDER_H_
