#include <engine/engine.hpp>

#include <stdarg.h>
#include <time.h>

void Engine::Log(ELoglevel loglevel, const char *format, ...) {
	if (loglevel < Loglevel) return;

	va_list ap;
	va_start(ap, format);

	vprintf(format, ap);

	va_end(ap);
}
