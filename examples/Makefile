# compiler setting
CC=g++
CFLAGS = -I../src
CFLAGS += -O2 -DNDEBUG
CFLAGS += -Wall
LFLAGS=



PROGS=demo interpol

all:		${PROGS}

demo:		demo.o
		${CC} $< -o $@

interpol:	interpol.o
		${CC} $< -o $@

%.o: %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f *.o ${PROGS} *.csv
