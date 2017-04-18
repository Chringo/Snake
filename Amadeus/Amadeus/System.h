#ifndef AMADEUS_MAIN_SYSTEM_H_
#define AMADEUS_MAIN_SYSTEM_H_
/// The format of the symbol name should be <SOLUTION>_<PROJECT>_<FILE>_H_
class System
{
public:
	System();
	~System();

	int Init();
	int Run();
	int Shutdown();
};
#endif // AMADEUS_MAIN_SYSTEM_H_