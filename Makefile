# Executable name
EXEC = cge

# Compiler binary and compiler flags
CXX = g++
CXXFLAGS = -Wall

# Source and object files
SRCS = main.cpp card.cpp deck.cpp player.cpp logger.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule is the first one
# Rule to link object files into the exectuable
$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS)

# Rule to compile objects from src
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule removes object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

# g++ -o software main.cpp card.cpp
