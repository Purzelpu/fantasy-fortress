CXX = g++
CXXFLAGS = -Wall
LDFLAGS = -lncurses

OBJ = Coordinate.o Bush.o Zwerg.o curses_output.o World.o start.o

start: $(OBJ)
	$(CXX) $(LDFLAGS) -o start $(OBJ)

Bush.o: Bush.cpp
Zwerg.o: Zwerg.cpp
curses_output.o: curses_output.cpp
World.o: World.cpp
Coordinate.o: Coordinate.cpp
start.o: start.cpp

.PHONY clean: 
	rm *.o
