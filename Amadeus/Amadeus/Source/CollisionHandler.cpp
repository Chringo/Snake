#include <Amadeus\CollisionHandler.h>
CollisionHandler::CollisionHandler()
{
	m_itemhitpreviousframe = false;
	notifier = nullptr;
	m_colmap = nullptr;
	m_height = 0;
	m_width = 0;
}
CollisionHandler::~CollisionHandler()
{
	Shutdown();
}

int CollisionHandler::Init(Notifier *notif, int * map, int height, int width)
{
	Shutdown();
	m_itemhitpreviousframe = false;
	notifier = notif;
	//for (int h = 0; h < height; h++)
	//{
	//	std::vector<int> row;
	//	for (int w = 0; w < width; w++)
	//	{
	//		row.push_back(map[h * height + w]);
	//	}
	//	m_colmap.push_back(row);
	//}	
	m_colmap = new int*[height];
	for (int h = 0; h < height; h++)
	{
		m_colmap[h] = new int[width];
		for (int w = 0; w < width; w++)
		{
			m_colmap[h][w] = map[h * height + w];
		}
	}
	m_height = height;
	m_width = width;
	std::random_device rd;// Obtain a new seed for each game instance, hence why it's local
	gen = std::mt19937(rd());// Load seed into generator
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
sf::Vector2i CollisionHandler::UpdateItem()
{
	std::vector<sf::Vector2i> spawnpoints;
	for (int h = 0; h < m_height; h++)
	{
		for (int w = 0; w < m_width; w++)
		{
			if (m_colmap[h][w] == 0)
			{
				spawnpoints.push_back(sf::Vector2i(w, h));
			}
		}
	}
	std::uniform_int_distribution<int> dis 
		= std::uniform_int_distribution<int>(0, (int)spawnpoints.size());
	return spawnpoints[dis(gen)];
}

void CollisionHandler::Print() const
{
	for (int h = 0; h < m_height; h++)//TEST
	{
		for (int w = 0; w < m_width; w++)
		{
			std::printf("%d ", m_colmap[h][w]);
		}
		std::printf("\n");
	}
}

void CollisionHandler::Shutdown()
{
	notifier = nullptr;
	if (m_colmap)
	{
		for (int h = 0; h < m_height; h++)
		{
			delete m_colmap[h];
		}
		delete[] m_colmap;
		m_colmap = nullptr;
	}
}
