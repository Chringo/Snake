#ifndef AMADEUS_MAIN_ITEMHOLDER_H_
#define AMADEUS_MAIN_ITEMHOLDER_H_
#include <SFML\Graphics.hpp>

class ItemHolder : public sf::Drawable
{
public:
	ItemHolder();
	~ItemHolder();

	int Init();
	int Respawn();

	sf::Vector2i getPos() const;
	int getPoints() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//Item *m_items;
	int m_activeitem;
	int m_numitems;
};
#endif // AMADEUS_MAIN_ITEMHOLDER_H_
