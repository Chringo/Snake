/// Use standard order for readability and to avoid hidden dependencies: 
/// Related header, C library, C++ library, other libraries' .h, your project's .h.
#include <crtdbg.h>
#include <Amadeus\System.h>

//int main(int argc, char *argv[])// Alternatively char **argv
int main()// Empty parameter list since we're not using any commands yet
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	System sys;
	sys.Init();
	sys.Run();
	sys.Shutdown();
	return 0;
}