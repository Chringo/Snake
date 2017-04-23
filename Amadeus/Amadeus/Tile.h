#ifndef AMADEUS_MAIN_TILE_H_
#define AMADEUS_MAIN_TILE_H_
#include <Amadeus\GridObject.h>
class Tile : public GridObject
{
public:
	Tile();
	~Tile();

	void Init(int type, int height, int width);

	bool isWall() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::RectangleShape shape;//TEST
	bool m_iswall;
};
#endif // AMADEUS_MAIN_TILE_H_