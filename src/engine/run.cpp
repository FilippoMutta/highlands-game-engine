#include <engine/engine.hpp>
#include <thread>

void Engine::Run() {
	Log(LOG_INFO, "Starting threads...\n");

	Log(LOG_DEBUG, "Starting event handler thread...\n");
	std::thread eventThread(HandleEvents);
	eventThread.join();
}
