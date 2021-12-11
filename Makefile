# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o 
CPP_FILES += $(wildcard *.cpp)
OBJS = main.o $(CPP_FILES:.cpp=.o)

# Use the cs225 makefile template:
include cs225/make/cs225.mk