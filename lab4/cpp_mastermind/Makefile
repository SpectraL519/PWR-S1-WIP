# TODO: os detection
# SHELL ALLIASSES
RM := del *.exe

# PROJECT STRUCTURE
SRC_FILES = main.cpp mastermind.cpp

# EXEC
EXEC := game

# CXX
CXX := g++
CXX_STD := -std=c++2a
# CXX_FLAGS := -Wall -Wpedantic -O3

# FLAGS
CXX_FLAGS :=
ifeq ($(CXX), clang++)
	CXX_FLAGS += -Weverything -pedantic -Wno-c++98-compat -g
else
	CXX_FLAGS += -Wall -Wextra -Wcast-align -Wconversion -Wunreachable-code -Wuninitialized -pedantic -g -O3
endif

# MAKE
COMPILE_ARGS = $(EXEC) $(SRC_FILES) $(CXX_STD)
STRICT ?= 1
ifeq ($(STRICT), 1)
	COMPILE_ARGS += $(CXX_FLAGS)
endif

game:
	$(CXX) -o $(COMPILE_ARGS)

clean:
	$(RM)
