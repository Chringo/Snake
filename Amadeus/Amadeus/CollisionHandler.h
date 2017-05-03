#ifndef AMADEUS_MAIN_COLLISIONHANDLER_H_
#define AMADEUS_MAIN_COLLISIONHANDLER_H_
#include <vector>
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	int Init(int *map, int height, int width);
private:
	void Shutdown();

	std::vector< std::vector<int> > m_colmap;
};
#endif