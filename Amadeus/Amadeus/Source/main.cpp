/// Use standard order for readability and to avoid hidden dependencies: 
/// Related header, C library, C++ library, other libraries' .h, this project's .h.
#include <crtdbg.h>
#include <Amadeus\System.h>

//int main(int argc, char *argv[])// Alternatively char **argv
int main()// Empty parameter list since we're not using any commands
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(9554);
	//_CrtSetBreakAlloc(9553);
	//_CrtSetBreakAlloc(9552);
	//_CrtSetBreakAlloc(9609);
	System sys;
	sys.Init();
	sys.Run();
	sys.Shutdown();
	return 0;
}