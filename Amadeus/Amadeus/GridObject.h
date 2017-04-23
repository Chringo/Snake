#ifndef AMADEUS_MAIN_GRIDOBJECT_H_
#define AMADEUS_MAIN_GRIDOBJECT_H_
#include <SFML\Graphics.hpp>
class GridObject : public sf::Drawable
{
public:
	GridObject();
	virtual ~GridObject();

	sf::Vector2i getGridPos() const;
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_gridpos;
};
#endif // AMADEUS_MAIN_GRIDOBJECT_H_