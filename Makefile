CXX = g++
CXXFLAGS = -Wall
LDFLAGS = -lncurses -ltinfo

OBJ = Coordinate.o Bush.o Zwerg.o CursesOutput.o World.o Action.o Move.o GrowBerries.o TakeBerries.o Job.o start.o

start: $(OBJ)
	$(CXX) $(LDFLAGS) -o start $(OBJ)

Bush.o: Bush.cpp
Zwerg.o: Zwerg.cpp
CursesOuput.o: CursesOutput.cpp
World.o: World.cpp
Coordinate.o: Coordinate.cpp
Action.o: Action.cpp
Move.o: Move.cpp
TakeBerries.o: TakeBerries.cpp
GrowBerries.o: GrowBerries.cpp
Job.o: Job.cpp
start.o: start.cpp

.PHONY clean: 
	rm *.o
