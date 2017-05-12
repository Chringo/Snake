#ifndef AMADEUS_MAIN_COLLISIONHANDLER_H_
#define AMADEUS_MAIN_COLLISIONHANDLER_H_
#include <random>// C++11
#include <SFML\System\Vector2.hpp>
#include <Amadeus\Notifier.h>
class Notifier;// TODO - Remove forward declaration by figuring out a better design between classes
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	int Init(Notifier *notifier, int *map, int height, int width);
	void UpdateSnake(const sf::Vector2i kFront, const sf::Vector2i kBack);
	void UpdateItem(const sf::Vector2i kItemPos);

	bool getPreviousFrameStatus() const { return m_itemhitpreviousframe; }
	sf::Vector2i getRandomPos();
	void Print() const;//TEST

private:
	void Shutdown();
	
	bool m_itemhitpreviousframe;
	int **m_colmap;
	int m_height;
	int m_width;
	Notifier *notifier;

	std::mt19937 gen;
};
#endif