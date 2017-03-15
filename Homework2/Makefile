CC=g++
CFLAGS=-c -g
LDFLAGS=
SOURCES=PagingDriver.cpp Page.cpp FIFOReplacementPolicy.cpp PageTable.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=PagingProgram

all: PagingProgram

PagingProgram: PagingDriver.o Page.o ReplacementPolicy.o FIFOReplacementPolicy.o PageTable.o LRUReplacementPolicy.o
	$(CC) PagingDriver.o Page.o ReplacementPolicy.o FIFOReplacementPolicy.o PageTable.o LRUReplacementPolicy.o -o PagingProgram

PagingDriver.o: PagingDriver.cpp
	$(CC) $(CFLAGS) PagingDriver.cpp

Page.o: Page.cpp
	$(CC) $(CFLAGS) Page.cpp

ReplacementPolicy.o: ReplacementPolicy.cpp
	$(CC) $(CFLAGS) ReplacementPolicy.cpp

FIFOReplacementPolicy.o: FIFOReplacementPolicy.cpp
	$(CC) $(CFLAGS) FIFOReplacementPolicy.cpp

PageTable.o: PageTable.cpp
	$(CC) $(CFLAGS) PageTable.cpp

LRUReplacementPolicy.o: LRUReplacementPolicy.cpp
	$(CC) $(CFLAGS) LRUReplacementPolicy.cpp

clean:
	rm *o PagingProgram
