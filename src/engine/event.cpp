#include <engine/engine.hpp>

#include <SDL2/SDL.h>
void Engine::HandleEvents() {
	SDL_Event event;

	bool quit = false;

	while (!quit) while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT){
			quit = true;
		}
		if (event.type == SDL_KEYDOWN){
			quit = true;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN){
			quit = true;
		}
	}

}
