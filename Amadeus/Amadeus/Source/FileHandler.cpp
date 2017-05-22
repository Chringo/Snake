#include <Amadeus\FileHandler.h>
#include <fstream>
#include <list>
FileHandler::FileHandler() {}
FileHandler::~FileHandler() {}

int ** FileHandler::LoadMap(std::string filepath, int * height, int * width, int ** map)
{
	filepath = "../Assets/Maps/" + filepath;

	std::ifstream stream(filepath);
	if (stream.is_open())
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
		char hfiller, wfiller;
		stream >> hfiller >> *height >> wfiller >> *width;
		std::printf("   Filler values: %c %c\n", hfiller, wfiller);
		map = new int*[*height];
		for (int h = 0; h < *height; h++)
		{
			map[h] = new int[*width];
			std::string row;
			stream >> row;
			//std::printf("%d - %s\n", h, row.c_str());
			for (int w = 0; w < *width; w++)
			{
				map[h][w] = row[w] - '0';
				//std::printf("%d", map[h][w]);
			}
			//std::printf("\n");
		}
		stream.close();
	}
	else
	{
		std::printf("FAILED - %s\n", filepath.c_str());
	}
	return map;
}

int FileHandler::LoadMap(std::string filepath)
{
	filepath = "../Assets/Maps/" + filepath;
	sf::FileInputStream stream;
	if (stream.open(filepath))
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
	}
	else
	{
		std::printf("FAILED - %s\n", filepath.c_str());
	}
	return 0;
}

int FileHandler::ImportFont(std::string filepath)
{
	filepath = "../Assets/Fonts/" + filepath;// arcade / ARCADE.ttf";
	if (m_mainfont.loadFromFile(filepath))
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
	}
	else
	{
		// Error message is produced by loadFromFile()
	}
	return 0;
}

void FileHandler::SaveSession(int points)
{
	std::string filepath = "../Assets/Saves/Leaderboard.txt";
	std::list<ScoreRow> leaderboard;
	std::ifstream instream(filepath);
	ScoreRow current;
	bool accepted = false;
	current.sr_points = points;
	current.sr_name = m_name;
	if (instream.is_open())
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
		for (int i = 0; i < 5; i++)
		{
			ScoreRow a;
			instream >> a.sr_points >> a.sr_name;
			if (!accepted && current > a)
			{
				leaderboard.push_back(current);
				accepted = true;
			}
			leaderboard.push_back(a);
		}
		instream.close();
	}
	else
	{
		std::printf("FAILED - %s\n", filepath.c_str());
	}
	int i = static_cast<int>(leaderboard.size());
	if (i < 5)
	{
		for (int j = i; j < 5; j++)
		{
			leaderboard.push_front(ScoreRow());
		}
	}
	std::ofstream outstream(filepath);
	for (i = 0; i < 5; i++)
	{
		const ScoreRow a = leaderboard.front();
		//std::printf("%s %d\n", a.sr_name.c_str(), a.sr_points);
		outstream << a.sr_points << " " << a.sr_name << '\n';
		leaderboard.pop_front();
	}
}

void FileHandler::setName(std::string name)
{
	m_name = name;
}

sf::Font * FileHandler::getFont()
{
	return &m_mainfont;
}

void FileHandler::LoadLeaderboard(sf::Text * leaderboard)
{
	std::string filepath = "../Assets/Saves/Leaderboard.txt";
	std::ifstream instream(filepath);
	if (instream.is_open())
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
		ScoreRow a;
		for (int i = 1; i < 6; i++)
		{
			instream >> a.sr_points >> a.sr_name;
			const std::string b = a.sr_name + " - " + std::to_string(a.sr_points);
			leaderboard[i].setString(b);
		}
		instream.close();
	}
	else
	{
		std::printf("FAILED - %s\n", filepath.c_str());
		for (int i = 1; i < 6; i++)
		{
			leaderboard[i].setString("NaN - 0");
		}
	}
}
