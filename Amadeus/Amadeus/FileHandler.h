#ifndef AMADEUS_MAIN_FILEHANDLER_H_
#define AMADEUS_MAIN_FILEHANDLER_H_
#include <SFML\System.hpp>
#include <SFML\Graphics\Font.hpp>
class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	int ** LoadMap(std::string filepath, int * height, int * width, int ** map);
	int LoadMap(std::string filepath);
	int ImportFont(std::string filepath);
	void SaveSession(int score);

	sf::Font * getFont();
private:
	sf::Font m_mainfont;
};
#endif // AMADEUS_MAIN_FILEHANDLER_H_