#ifndef AMADEUS_MAIN_ITEM_H_
#define AMADEUS_MAIN_ITEM_H_
#include <SFML\Graphics.hpp>
class Item : public sf::Drawable
{
public:
	Item();
	~Item();

	void Init(sf::Vector2i gridpos, int points);
	sf::Vector2i getGridPos() const;
	int getPoints() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::CircleShape shape;//TEST
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_gridpos;
	int m_points;
};
#endif // AMADEUS_MAIN_ITEM_H_
