
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= ExpresionRegular.o Nodo.o Alfabeto.o ER2Tree.o mainER2Tree.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o ER2Tree ${OBJS}

clean:
	rm -rf *.o *.txt ER2Tree
