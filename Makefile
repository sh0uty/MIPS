CC = g++
INCLUDES = -I. -I/usr/local/systemc233/include
LIBS = -L/usr/local/systemc233/lib-linux64
LIBFLAGS = -lm -lsystemc

TARGET = MIPS
OBJ = data_memory.o control.o alu.o alu_control.o adder.o mux.o pc.o registers.o shifter.o sign_extend.o main.o

$(TARGET): $(OBJ)
	@echo "Compiling MIPS binary..."
	$(CC) $(INCLUDES) $(LIBS) -o $@ $^ $(LIBFLAGS) -static

%.o: %.cpp
	@echo "Compiling MIPS::$@ object files..."
	$(CC) $(INCLUDES) -c $^


#main.o: main.cpp
#	@echo "Compiling MIPS::$@ object files..."
#	$(CC) $(INCLUDES) -c $^
#
#shifter.o: shifter.cpp
#	@echo "Compiling MIPS::$@ object files..."
#	$(CC) $(INCLUDES) -c $^
#
#sign_extend.o: sign_extend.cpp
#	@echo "Compiling MIPS::$@ object files..."
#	$(CC) $(INCLUDES) -c $^

clean:
	$(RM) $(TARGET) $(wildcard *.o) $(TARGET).vcd
