#ifndef AMADEUS_MAIN_NOTIFIER_H_
#define AMADEUS_MAIN_NOTIFIER_H_
#include <Amadeus\SnakeHolder.h>
#include <Amadeus\ItemHolder.h>
class Notifier
{
public:
	Notifier();
	~Notifier();

	int Init(SnakeHolder *sh, ItemHolder *ih);
	void Notify(int input);
	bool getLost() const;
private:
	bool m_lost;
	SnakeHolder *snakeholder;
	ItemHolder *itemholder;
};
#endif