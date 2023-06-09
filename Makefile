SRCDIR = src

CPP = g++
LD = g++

CFLAGS := `sdl2-config --libs --cflags` -Wall -Wextra -Weffc++ -ggdb3 -I $(SRCDIR)/include

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CPPSRC = $(call rwildcard,$(SRCDIR),*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(SRCDIR)/%.o, $(CPPSRC))

.PHONY: dynamic static mkmi

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	@ echo !==== COMPILING MKMI $^ && \
	$(CPP) $(CFLAGS) -c $^ -o $@

engine: $(OBJS)
	@ echo !==== LINKING
	$(LD) $(CFLAGS) -o engine $(OBJS)

clean:
	@rm $(OBJS)
