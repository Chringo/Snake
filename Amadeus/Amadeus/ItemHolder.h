#ifndef AMADEUS_MAIN_ITEMHOLDER_H_
#define AMADEUS_MAIN_ITEMHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Item.h>
class ItemHolder : public sf::Drawable
{
public:
	ItemHolder();
	~ItemHolder();

	int Init();
	int Respawn();

	sf::Vector2i getActiveItemPos() const;
	int getPoints() const;
private:
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	Item *m_items;
	int m_activeitem;
	int m_numitems;
};
#endif // AMADEUS_MAIN_ITEMHOLDER_H_
