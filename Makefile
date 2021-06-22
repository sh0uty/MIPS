CC = g++
INCLUDES = -I/src -I/usr/local/systemc233/include
LIBS = -L/usr/local/systemc233/lib-linux64
LIBFLAGS = -lm -lsystemc

TARGET = MIPS

rm = rm -f

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	mkdir -p bin
	@echo "Linking MIPS binary..."
	@$(CC) $(OBJECTS) $(INCLUDES) $(LIBS) -o $@ $(LIBFLAGS) -static

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p obj
	@echo "Compiling MIPS::$^ object file"
	$(CC) $(INCLUDES) -c $^ -o $@

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Removed all object files"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed"