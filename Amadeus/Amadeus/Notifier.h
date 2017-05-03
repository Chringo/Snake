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
private:

};
#endif