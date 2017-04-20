#ifndef AMADEUS_MAIN_SYSTEM_H_
#define AMADEUS_MAIN_SYSTEM_H_
/// The format of the symbol name should be <SOLUTION>_<PROJECT>_<FILE>_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Game.h>
class System
{
/// Separate functions and variables, functions comes first.
/// Order headers as followed; public, protected, and private.
public:
	System();
	~System();

	int Init();
	int Run();
	int Shutdown();
private:
	void Render();

	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Game m_game;
};
#endif // AMADEUS_MAIN_SYSTEM_H_