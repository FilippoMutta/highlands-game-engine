#include <engine/engine.hpp>

enum ESection {
	SECTION_UNKNOWN,
	SECTION_ENGINE,
	SECTION_GENERAL,
	SECTION_VIDEO
};

enum EKey {
	KEY_UNKNOWN,
	KEY_ENGINE_VERSION,
	KEY_VIDEO_WIDTH,
	KEY_VIDEO_HEIGHT,
};

ESection GetSection(const char *section) {
	if (strcmp(section, "Engine") == 0) {
		return SECTION_ENGINE;
	} else if (strcmp(section, "General") == 0) {
		return SECTION_GENERAL;
	} else if (strcmp(section, "Video") == 0) {
		return SECTION_VIDEO;
	} else {
		return SECTION_UNKNOWN;
	}
}

EKey GetKey(ESection section, const char *key) {
	switch(section) {
		case SECTION_ENGINE:
			if (strcmp(key, "Version") == 0) {
				return KEY_ENGINE_VERSION;
			} else {
				return KEY_UNKNOWN;
			}
		case SECTION_VIDEO:
			if (strcmp(key, "ScreenWidth") == 0) {
				return KEY_VIDEO_WIDTH;
			} else if (strcmp(key, "ScreenHeight") == 0) {
				return KEY_VIDEO_HEIGHT;
			} else {
				return KEY_UNKNOWN;
			}
		default:
			return KEY_UNKNOWN;
	}
}

void Engine::ProcessConfigKey(const char *section, const char *key, const char *value) {
	Log(LOG_DEBUG, "Section: %s, Key: %s, Value: %s\n", section, key, value);

	switch(GetKey(GetSection(section), key)) {
		case KEY_ENGINE_VERSION:
			break;
		case KEY_VIDEO_WIDTH:
			ScreenWidth = atoi(value);
			break;
		case KEY_VIDEO_HEIGHT:
			ScreenHeight = atoi(value);
			break;
		case KEY_UNKNOWN:
			break;
	}
}

void Engine::LoadConfiguration() {
	FILE *file = fopen(ConfigPath, "r");

	if (file == NULL) {
		Log(LOG_ERROR, "Failed to open configuration file!\n");
		return;
	}

	char *lineBuffer = NULL;
	char *currentSection = NULL;
	size_t lineLength = 0;


	while (getline(&lineBuffer, &lineLength, file) != -1) {
		char *trimmedLine = strtok(lineBuffer, "\t\r\n");

		if (trimmedLine != NULL && trimmedLine[0] != ';' && trimmedLine[0] != '#') {
			size_t stringLength = strlen(trimmedLine);
			if (trimmedLine[0] == '[' && trimmedLine[stringLength - 1] == ']') {
				if(currentSection != NULL) {
					delete currentSection;
					currentSection = NULL;
				}

				currentSection = new char[stringLength - 1];
				strncpy(currentSection, trimmedLine + 1, stringLength - 2);
				currentSection[stringLength - 2] = '\0';
				
			} else {
				const char *key = strtok(trimmedLine, "= ");
				const char *value = strtok(NULL, "= ");

				if (key != NULL && value != NULL) {
					ProcessConfigKey(currentSection, key, value);
				}
			}

		}

		delete lineBuffer;
		lineBuffer = NULL;
	}


	fclose(file);
}
