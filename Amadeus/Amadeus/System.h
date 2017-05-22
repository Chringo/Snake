#ifndef AMADEUS_MAIN_SYSTEM_H_
#define AMADEUS_MAIN_SYSTEM_H_
/// Three slashes - /// - are dedicated to style guide references.
/// The style guide is based upon Google's C++ Style Guide.
/// The format of the symbol name should be <SOLUTION>_<PROJECT>_<FILE>_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\Game.h>
#include <Amadeus\FileHandler.h>
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
	sf::String PlayerSetsName();
	void Render();
	void HandleEvents();
	void MouseEvent(int x, int y);// Look for intersections with mouse on menu options.
	// Menu options are Start, maps, and exit.
/// Name of constant begins with <k> followed by capital letter per word in variable name.
/// This rule is applied on all member variables, local variables and on parameters in header-files.
	void PerformanceTests(const float kLastFrame);
	void MenuSetup(int numberofmaps);

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	bool m_vsync;
	bool m_performance;
	bool m_mapchosen;
	bool m_gamerunning;
	Game m_game;
	FileHandler m_data;

	// Performance tests
	int m_numframes = 0;
	float m_elapsedtime = 0;
	float m_longest = 10000;
	float m_shortest = 0;
#ifdef _DEBUG
	// MouseHit tests
	sf::RectangleShape m_bounds[5];
#endif // _DEBUG

	// Graphical text representing the menu in System
	sf::Text m_playername; // Initiates m_data with name string.
	sf::Text m_leaderboard[6];
	sf::Text m_center[3];
	sf::Text m_mapoptions[3];
};
#endif // AMADEUS_MAIN_SYSTEM_H_