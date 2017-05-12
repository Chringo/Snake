#ifndef AMADEUS_MAIN_MAPHOLDER_H_
#define AMADEUS_MAIN_MAPHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Tile.h>
class MapHolder : public sf::Drawable
{
public:
	MapHolder();
	~MapHolder();

	int Init(const int kHeight, const int kWidth, int ** map);
private:
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	Tile ** m_map;
	int m_height;
	int m_width;
};
#endif // AMADEUS_MAIN_MAPHOLDER_H_