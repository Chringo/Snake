#ifndef AMADEUS_MAIN_MAPHOLDER_H_
#define AMADEUS_MAIN_MAPHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Tile.h>
class MapHolder : public sf::Drawable
{
public:
	MapHolder();
	~MapHolder();

	int Init(int *map, int size);
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	Tile *m_map;
	int m_numtiles;
};
#endif // AMADEUS_MAIN_MAPHOLDER_H_