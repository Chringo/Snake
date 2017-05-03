#ifndef AMADEUS_MAIN_SYSTEM_H_
#define AMADEUS_MAIN_SYSTEM_H_
/// Three slashes - /// - are dedicated to style guide references.
/// The style guide is based upon Google's C++ Style Guide.
/// The format of the symbol name should be <SOLUTION>_<PROJECT>_<FILE>_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Game.h>
class System
{
/// Separate functions and variables, functions comes first.
/// Order headers as followed; public, protected, and private.
/// Member variables starts with <m_> and are lowercase.
public:
	System();
	~System();

	int Init();
	int Run();
	int Shutdown();
private:
	void Render();
	void PerformanceTests(const float lastframe);

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	Game m_game;

	// Performance tests
	int m_numframes = 0;
	float m_elapsedtime = 0;
	float m_longestframe = 0;
	float m_shortestframe = 100;
};
#endif // AMADEUS_MAIN_SYSTEM_H_