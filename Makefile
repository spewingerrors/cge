
# Compiler binary and compiler flags
CXX = g++
CXXFLAGS = -Wall

# Source and object files
SRCS = main.cpp card.cpp deck.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = software

# Rule to link object files into the exectuable
$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS) 

# Default Rule: build the executable
#all:
#	$(SRCS) $(EXEC)

# Rule to compile objects from src
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule removes object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

# g++ -o software main.cpp card.cpp
