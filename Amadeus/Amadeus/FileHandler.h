#ifndef AMADEUS_MAIN_FILEHANDLER_H_
#define AMADEUS_MAIN_FILEHANDLER_H_
#include <SFML\System.hpp>
class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	int ** LoadMap(std::string filepath, int * height, int * width, int ** map);
	int LoadMap(std::string filepath);
};
#endif // AMADEUS_MAIN_FILEHANDLER_H_