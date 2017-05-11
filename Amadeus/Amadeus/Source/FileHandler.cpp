#include <Amadeus\FileHandler.h>
#include <fstream>
FileHandler::FileHandler()
{
}
FileHandler::~FileHandler()
{
}

int FileHandler::LoadMap(std::string filepath, int * height, int * width, int * map)
{
	filepath = "../Assets/Maps/" + filepath;
	
	std::ifstream stream(filepath);
	if (stream.is_open())
	{
		std::printf("ACCESSING - %s\n", filepath.c_str());
		char hfiller, wfiller;
		stream >> hfiller >> *height >> wfiller >> *width;
		std::printf("%c %c\n", hfiller, wfiller);
		//map = new int*[*height];
		//for (int h = 0; h < *height; h++)
		//{
		//	map[h] = new int[*width];
		//	std::string row;
		//	stream >> row;
		//	//std::printf("%d - %s\n", h, row.c_str());
		//	for (int w = 0; w < *width; w++)
		//	{
		//		map[h][w] = row[w] - '0';
		//		std::printf("%d ", map[h][w]);
		//	}
		//	std::printf("\n");
		//}
		map = new int[*height * *width];
		for (int h = 0; h < *height; h++)
		{
			std::string row;
			stream >> row;
			//std::printf("%d - %s\n", h, row.c_str());
			for (int w = 0; w < *width; w++)
			{
				map[h * *height + w] = row[w] - '0';
				std::printf("%d ", map[h * *height + w]);
			}
			std::printf("\n");
		}
	}
	else
	{
		std::printf("FAILED - %s\n", filepath.c_str());
	}
	return 0;
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
