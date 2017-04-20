#ifndef AMADEUS_MAIN_GAME_H_
#define AMADEUS_MAIN_GAME_H_
#include <SFML\Graphics.hpp>
class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	int Init();
	int Update(const sf::Event &e, float dt);
	void Shutdown();

	int getHighScore() const;
private:
	void HandleInput(const sf::Event &e);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int m_score;
};
#endif // AMADEUS_MAIN_GAME_H_