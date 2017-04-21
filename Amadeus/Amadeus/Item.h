#ifndef AMADEUS_MAIN_ITEM_H_
#define AMADEUS_MAIN_ITEM_H_
#include <SFML\Graphics.hpp>
class Item : public sf::Drawable
{
public:
	Item();
	~Item();

	int getPoints() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::RectangleShape shape;//TEST
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_points;
};
#endif // AMADEUS_MAIN_ITEM_H_
