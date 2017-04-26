#ifndef AMADEUS_MAIN_GRIDOBJECT_H_
#define AMADEUS_MAIN_GRIDOBJECT_H_
#include <SFML\Graphics.hpp>
class GridObject : public sf::Drawable
{
public:
	GridObject();
	virtual ~GridObject();

	void setGridPos(sf::Vector2i newpos);
	sf::Vector2i getGridPos() const;
protected:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_gridpos;
};
#endif // AMADEUS_MAIN_GRIDOBJECT_H_