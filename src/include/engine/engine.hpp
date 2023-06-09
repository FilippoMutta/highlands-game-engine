#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <engine/video/display.hpp>

enum ELoglevel {
	LOG_DEBUG = 0,
	LOG_INFO = 1,
	LOG_WARNING = 2,
	LOG_ERROR = 3,
	LOG_FATAL = 4
};

class Engine {
public:
	Engine();
	~Engine();

	void ParseArgs(int *argc, char **argv);
	void LoadConfiguration();

	void StartDisplay();
	void KillDisplay();

	void Run();

	void Log(ELoglevel loglevel, const char *format, ...);
private:
	static void HandleEvents();

	void ProcessConfigKey(const char *section, const char *key, const char *value);

	GameDisplay *MainDisplay = NULL;

	unsigned short ScreenWidth = 0;
	unsigned short ScreenHeight = 0;

	const char *ConfigPath = "config.ini";
	const char *LogPath = "engine.log";

	ELoglevel Loglevel;
};

int InstantiateEngine();
Engine *GetEngine();
