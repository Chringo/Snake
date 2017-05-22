#ifndef AMADEUS_MAIN_FILEHANDLER_H_
#define AMADEUS_MAIN_FILEHANDLER_H_
#include <SFML\System.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	int ** LoadMap(std::string filepath, int * height, int * width, int ** map);
	int LoadMap(std::string filepath);
	int ImportFont(std::string filepath);
	void SaveSession(int points);
	void LoadLeaderboard(sf::Text * leaderboard);

	void setName(std::string name);
	sf::Font * getFont();
private:
	struct ScoreRow
	{
		int sr_points = 0;
		std::string sr_name = "NaN";
		bool operator>(ScoreRow a)
		{
			if (sr_points > a.sr_points)
				return true;
			else
				return false;
		}
	};

	std::string m_name;
	sf::Font m_mainfont;
};
#endif // AMADEUS_MAIN_FILEHANDLER_H_