#Executable name
EXECUTABLE = sorting_network

#Compiler
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

#Source directories
SRC_DIRS = odd-even_transposition_sort \
           odd-even_mergesort \
           bitonic_sort \
           adapted_bitonic_sort \
           ls3_sort \
           4-way_mergesort \
           rotatesort \
           3n_sort_Schnorr_and_Shamir \
           2D_odd-even_transposition_sort \
           shearsort

#Source file
SRC = main.cpp \
      $(wildcard $(patsubst %, %/*.cpp, $(SRC_DIRS)))

#Objective file
OBJ = $(SRC:.cpp=.o)


#Main rule
all: $(EXECUTABLE)

#Executable creation rule
$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Rule for compiling .cpp files into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


#Clean objects and executable files
clean:
	rm -f $(OBJ) $(EXECUTABLE)
