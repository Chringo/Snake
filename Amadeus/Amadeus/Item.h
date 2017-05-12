#ifndef AMADEUS_MAIN_ITEM_H_
#define AMADEUS_MAIN_ITEM_H_
#include <Amadeus\GridObject.h>
class Item : public GridObject
{
public:
	Item();
	~Item();

	void Init(int points);
	void setGridPos(const int kX, const int kY);
	int getPoints() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::CircleShape shape;//TEST
	int m_points;
};
#endif // AMADEUS_MAIN_ITEM_H_
