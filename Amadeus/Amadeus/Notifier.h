#ifndef AMADEUS_MAIN_NOTIFIER_H_
#define AMADEUS_MAIN_NOTIFIER_H_
#include <Amadeus\SnakeHolder.h>
#include <Amadeus\ItemHolder.h>
class Notifier
{
public:
/// Enumerators (for both scoped and unscoped enums) should be named as <ENUM_NAME_WITH_SPACES>.
	// enum class - scoped and strongly typed enum
	enum class Flag
	{
		GAME_OVER,
		ITEM_HIT
	};

	Notifier();
	~Notifier();

	int Init(SnakeHolder *snakeholder, ItemHolder *itemholder);
	void Notify(Flag input);
	bool getLost() const;
private:
	bool m_lost;
	SnakeHolder *snakeholder;
	ItemHolder *itemholder;
};
#endif