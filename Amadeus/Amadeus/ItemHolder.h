#ifndef AMADEUS_MAIN_ITEMHOLDER_H_
#define AMADEUS_MAIN_ITEMHOLDER_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Item.h>
class ItemHolder : public sf::Drawable
{
public:
	ItemHolder();
	~ItemHolder();

	int Init(int numitems, int startingpointvalue);
	int Respawn(sf::Vector2i freeposition);

	int UpdateScore();// Updates after an item has been hit
	int getHighScore() const;// Called when player has lost
	sf::Vector2i getActiveItemPos() const;
private:
	int getPoints() const;
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int m_activeitem;
	int m_numitems;
	int m_currentscore;
	Item *m_items;
};
#endif // AMADEUS_MAIN_ITEMHOLDER_H_
