#pragma once
#include <SDL2/SDL.h>

class Engine;

class GameDisplay {
public:
	GameDisplay(Engine *parent, const char *title, unsigned int width, unsigned int height);
	~GameDisplay();
private:
	unsigned int ScreenWidth;
	unsigned int ScreenHeight;
	const char *WindowTitle;

	SDL_Window *Window;
	SDL_Renderer *Renderer;

	Engine *Parent;
};
