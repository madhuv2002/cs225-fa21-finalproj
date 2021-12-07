EXENAME = main
OBJS = main.o routemap.o stoppoint.o edge.o visualizer.o
# Use the cs225 makefile template:
include cs225/make/cs225.mk
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
