#include <Amadeus\CollisionHandler.h>
CollisionHandler::CollisionHandler()
{
}
CollisionHandler::~CollisionHandler()
{
}

int CollisionHandler::Init(int * map, int height, int width)
{
	Shutdown();
	for (int h = 0; h < height; h++)
	{
		std::vector<int> row;
		for (int w = 0; w < width; w++)
		{
			row.push_back(map[h * height + w]);
		}
		m_colmap.push_back(row);
	}
	return 0;
}


void CollisionHandler::Shutdown()
{

}
