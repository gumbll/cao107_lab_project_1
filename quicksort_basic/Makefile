# vim: set noet:

CC=g++
CFLAGS=-I. -lpthread -I../inc/gsl/include
OUTDIR=build
SOURCES=main.cpp Timer.cpp
DEPS=Timer.h
EXE=$(OUTDIR)/quicksort_basic
OBJ=$(patsubst %.cpp, $(OUTDIR)/%.o, $(SOURCES))

all: build $(EXE)

# $@ is a variable for whatever is on left of rule
# $^ is first thing on right of it, I guess $> is the rest?

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OUTDIR)/%.o : %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

build:
	@mkdir -p build
