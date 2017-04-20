#include <Amadeus\Game.h>

Game::Game() {}
Game::~Game() {}

int Game::Init()
{
	m_score = 0;
	return 0;
}

int Game::Update(const sf::Event &e, float dt)
{
	std::printf("%.6f\n", dt);
	return 0;
}

void Game::Shutdown()
{

}

int Game::getHighScore() const
{
	return m_score;
}

void Game::HandleInput(const sf::Event &e)
{

}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	target.draw(shape, states);
}