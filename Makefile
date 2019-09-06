CXXFLAGS = -Wall
LDFLAGS = -lncurses -ltinfo

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

start: $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o start

.PHONY clean: 
	rm *.o
