GXX=g++
CFLAGS=-Wall --pedantic
CLIBS=

wordle: wordle.o
	${GXX} $^ -o $@ ${CFLAGS} ${CLIBS}

wordle.o: wordle.cpp
	${GXX} -c $^ ${CFLAGS} ${CLIBS}

.PHONY: clean
clean:
	rm -rf *.o wordle
