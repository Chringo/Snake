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

	const float m_size = 26.0f;
	sf::Vector2i m_gridpos;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
#endif // AMADEUS_MAIN_GRIDOBJECT_H_