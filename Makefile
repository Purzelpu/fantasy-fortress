CXXFLAGS = -Wall
LDFLAGS = -lncurses -ltinfo

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

start: $(OBJ)
	$(CXX) $(LDFLAGS) -o start $(OBJ)

.PHONY clean: 
	rm *.o
