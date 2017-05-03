#include <Amadeus\CollisionHandler.h>
CollisionHandler::CollisionHandler()
{
	notif = nullptr;
}
CollisionHandler::~CollisionHandler()
{
}

int CollisionHandler::Init(Notifier *notifier, int * map, int height, int width)
{
	Shutdown();
	notif = notifier;
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

void CollisionHandler::UpdateSnake(const sf::Vector2i front, const sf::Vector2i back)
{
	m_colmap[front.y][front.x] = 3;
	m_colmap[back.y][back.x] = 0;
}

void CollisionHandler::Print() const
{
	for (int h = 0; h < m_colmap.size(); h++)//TEST
	{
		for (int w = 0; w < m_colmap[0].size(); w++)
		{
			std::printf("%d ", m_colmap[h][w]);
		}
		std::printf("\n");
	}
}

void CollisionHandler::Shutdown()
{
	notif = nullptr;
	m_colmap.clear();
}
