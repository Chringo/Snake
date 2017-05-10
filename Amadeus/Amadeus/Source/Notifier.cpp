#include <Amadeus\Notifier.h>
Notifier::Notifier()
{
	m_lost = false;
}
Notifier::~Notifier()
{
}

int Notifier::Init(SnakeHolder * sh, ItemHolder * ih, CollisionHandler *ch)
{
	m_lost = false;
	snakeholder = sh;
	itemholder = ih;
	colhandler = ch;
	return 0;
}

void Notifier::Notify(Flag input)
{
	if (input == Flag::GAME_OVER)
	{
		m_lost = true;
	}
	else if (input == Flag::ITEM_HIT)
	{
		snakeholder->Add();
		std::printf("%d\n", itemholder->UpdateScore());
		itemholder->Respawn(colhandler->getRandomPos());
		colhandler->UpdateItem(itemholder->getActiveItemPos());
	}
}

bool Notifier::getLost() const
{
	return m_lost;
}
