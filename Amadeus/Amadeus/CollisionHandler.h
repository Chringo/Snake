#ifndef AMADEUS_MAIN_COLLISIONHANDLER_H_
#define AMADEUS_MAIN_COLLISIONHANDLER_H_
//#include <vector>
#include <random>// C++11
#include <SFML\System\Vector2.hpp>
#include <Amadeus\Notifier.h>
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	int Init(Notifier *notifier, int *map, int height, int width);
	void UpdateSnake(const sf::Vector2i front, const sf::Vector2i back);
	void UpdateItem(const sf::Vector2i itemPos);

	sf::Vector2i UpdateItem();

	void Print() const;//TEST

private:
	void Shutdown();
	
	bool m_itemhitpreviousframe;
	//std::vector< std::vector<int> > m_colmap;
	int **m_colmap;
	int m_height;
	int m_width;
	Notifier *notifier;

	std::mt19937 gen;
};
#endif