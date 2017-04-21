#ifndef AMADEUS_MAIN_TILE_H_
#define AMADEUS_MAIN_TILE_H_
#include <SFML\Graphics.hpp>
class Tile : public sf::Drawable
{
public:
	Tile();
	~Tile();

	void Init(int type, int height, int width);

	bool isWall() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::RectangleShape shape;//TEST
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	bool m_iswall;
};
#endif // AMADEUS_MAIN_TILE_H_