#include <engine/video/display.hpp>
#include <engine/engine.hpp>

void Engine::StartDisplay() {
	if (MainDisplay != NULL) delete MainDisplay;
	MainDisplay = NULL;

	MainDisplay = new GameDisplay(this, "Game window", ScreenWidth, ScreenHeight);

	if (MainDisplay == NULL)  {
		Log(LOG_FATAL, "Failed to allocate memory for GameDisplay.\n");
	}
}

GameDisplay::GameDisplay(Engine *parent, const char *title, unsigned int width, unsigned int height)
	: WindowTitle(title), ScreenWidth(width), ScreenHeight(height), Parent(parent) {
	Parent->Log(LOG_INFO, "Initializing window...\n");
	
	Parent->Log(LOG_DEBUG, "Creating window %s...\n", WindowTitle);
	Window = SDL_CreateWindow(WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0 /*SDL_WINDOW_FULLSCREEN || SDL_WINDOW_BORDERLESS*/);

	Parent->Log(LOG_DEBUG, "Creating renderer...\n");
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Parent->Log(LOG_DEBUG, "Presenting renderer...\n");
	SDL_SetRenderDrawColor(Renderer, 69, 69, 69, 255);
	SDL_RenderClear(Renderer);
	SDL_RenderPresent(Renderer);
	
	Parent->Log(LOG_INFO, "Window initialized.\r\n");
}
	
GameDisplay::~GameDisplay() {
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
}
