#ifndef AMADEUS_MAIN_GAME_H_
#define AMADEUS_MAIN_GAME_H_
#include <SFML\Graphics.hpp>
#include <Amadeus\MapHolder.h>
#include <Amadeus\ItemHolder.h>
#include <Amadeus\SnakeHolder.h>
#include <Amadeus\CollisionHandler.h>
class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	int Init();
	int Update(const sf::Event &e, float dt);
	void Shutdown();
	void HandleInput(const sf::Event &e);

	int getHighScore() const;
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int m_score;
	MapHolder *m_mapholder;
	ItemHolder *m_itemholder;
	SnakeHolder *m_snakeholder;
	CollisionHandler *m_colhandler;

	sf::Texture m_backtexture;
	sf::Sprite m_backsprite;
};
#endif // AMADEUS_MAIN_GAME_H_