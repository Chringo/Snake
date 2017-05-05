#include <Amadeus\CollisionHandler.h>
CollisionHandler::CollisionHandler()
{
	m_itemhitpreviousframe = false;
	notifier = nullptr;
}
CollisionHandler::~CollisionHandler()
{
}

int CollisionHandler::Init(Notifier *notif, int * map, int height, int width)
{
	Shutdown();
	m_itemhitpreviousframe = false;
	notifier = notif;
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
	if (!m_itemhitpreviousframe)
	{
		m_colmap[back.y][back.x] = 0;
	}
	else
	{
		m_itemhitpreviousframe = false;
	}
	if (m_colmap[front.y][front.x] == 1 || m_colmap[front.y][front.x] == 3)
	{
		std::printf("GAME_OVER");
		notifier->Notify(Notifier::Flag::GAME_OVER);
	}
	else if (m_colmap[front.y][front.x] == 2)
	{
		std::printf("ITEM_HIT");
		m_itemhitpreviousframe = true;
		notifier->Notify(Notifier::Flag::ITEM_HIT);
	}
	m_colmap[front.y][front.x] = 3;
}

void CollisionHandler::UpdateItem(const sf::Vector2i pos)
{
	if (m_colmap[pos.y][pos.x] != 2)
	{
		m_colmap[pos.y][pos.x] = 2;
	}
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
	notifier = nullptr;
	m_colmap.clear();
}
