#include <engine/engine.hpp>

#include <SDL2/SDL.h>

int main(int *argc, char **argv) {
	if (int code = SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("FATAL ERROR: Failed to initialize SDL: %s\n", SDL_GetError());
		exit(code);
	}

	if(int code = InstantiateEngine() != 0) {
		printf("FATAL ERROR: Failed to instantiate engine");
		exit(code);
	}

	Engine *engine = GetEngine();

	engine->Log(LOG_INFO, "Engine initialized.\n");

	engine->ParseArgs(argc, argv);
	engine->LoadConfiguration();
	engine->StartDisplay();

	engine->Run();

	engine->Log(LOG_INFO, "Exiting...\n");

	SDL_Quit();

	return 0;
}
