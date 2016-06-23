# Makefile for ReversibleNumbers
G=g++
FLAGS=-Wall -g
SOURCES=src/Rev.cpp
EXEC=Rev.e
TEST_PARMS=89978

all: $(EXEC) clean
	
exec: $(EXEC)
	
test: exec
	$(CURDIR)/bin/$(EXEC) $(TEST_PARMS)

$(EXEC): Rev.o
	$(G) $(FLAGS) -o $(CURDIR)/bin/$(EXEC) $^
Rev.o: $(SOURCES)
	$(G) $(FLAGS) -c -o $@ $^
clean:
	$(RM) *.o
clean_exec:
	$(RM) $(CURDIR)/bin/$(EXEC)
