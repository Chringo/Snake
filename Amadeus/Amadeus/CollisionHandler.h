#ifndef AMADEUS_MAIN_COLLISIONHANDLER_H_
#define AMADEUS_MAIN_COLLISIONHANDLER_H_
#include <vector>
#include <SFML\System\Vector2.hpp>
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	int Init(int *map, int height, int width);
	void UpdateSnake(const sf::Vector2i front, const sf::Vector2i back);

	void Print() const;//TEST
private:
	void Shutdown();

	std::vector< std::vector<int> > m_colmap;
};
#endif