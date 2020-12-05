TARGET    = Polygons

# Compile
CC        = gcc
CFLAGS    = -std=c99 -Wall -c -I. 

# Linker
LINKER    = gcc
SDL       = -I /usr/local/include/SDL2/ -F /Library/Frameworks -framework SDL2
LFLAGS    = -Wall -I. -lm $(SDL)

# Directories
SRCDIR    = src
OBJDIR    = obj
BINDIR    = bin

SOURCES   := $(wildcard $(SRCDIR)/*.c)
INCLUDES  := $(wildcard $(SRCDIR)/*.h)
OBJECTS   := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET).exe: $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@rm -f $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@rm -f $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
