CC = /usr/bin/g++
CFLAGS = -g -O0 -fopenmp
LD = /usr/bin/g++
LDFLAGS = -g -fopenmp

PROGRAM = main

all:	${PROGRAM}

${PROGRAM}: ${PROGRAM}.o
	${LD} ${LDFLAGS} $< -o ${PROGRAM}

${PROGRAM}.o: ${PROGRAM}.cpp
	${CC} ${CFLAGS} -c $< -o ${PROGRAM}.o

clean:
	rm -f ${PROGRAM}.o ${PROGRAM}