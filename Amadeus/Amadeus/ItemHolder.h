#ifndef AMADEUS_MAIN_ITEMHOLDER_H_
#define AMADEUS_MAIN_ITEMHOLDER_H_
#include <random>// C++11
#include <SFML\Graphics.hpp>
#include <Amadeus\Item.h>
class ItemHolder : public sf::Drawable
{
public:
	ItemHolder();
	~ItemHolder();

	int Init(const int HEIGHT, const int WIDTH, int *map);
	int Respawn();

	int UpdateScore();
	sf::Vector2i getActiveItemPos() const;
private:
	int getPoints() const;
	void Shutdown();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int m_activeitem;
	int m_numitems;
	int m_currentscore;
	Item *m_items;

	//std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen; // Standard 32-bit mersenne_twister_engine seeded with rd()
	// http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::uniform_int_distribution<int> disx;
	std::uniform_int_distribution<int> disy;
};
#endif // AMADEUS_MAIN_ITEMHOLDER_H_
