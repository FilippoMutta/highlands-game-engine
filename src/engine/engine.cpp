#include <engine/engine.hpp>

Engine *GameEngine = NULL;

int InstantiateEngine() {
	GameEngine = new Engine();

	if (GameEngine == NULL) return -1;

	return 0;
}

Engine *GetEngine() {
	return GameEngine;
}

Engine::Engine() {
	Loglevel = LOG_DEBUG;
}

Engine::~Engine() {

}
