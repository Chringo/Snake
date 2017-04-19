#ifndef AMADEUS_MAIN_SYSTEM_H_
#define AMADEUS_MAIN_SYSTEM_H_
/// The format of the symbol name should be <SOLUTION>_<PROJECT>_<FILE>_H_
#include <SFML\Graphics.hpp>
class System
{
private:
	sf::RenderWindow m_window;
	sf::CircleShape shape;
	//sf::Clock dt;


	void Render();
public:
	System();
	~System();

	int Init();
	int Run();
	int Shutdown();
};
#endif // AMADEUS_MAIN_SYSTEM_H_