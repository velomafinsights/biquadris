CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/opt/X11/lib -lX11 -I/opt/X11/include
EXEC = biquadris
OBJECTS =  gameboard.o level.o level0.o level1.o level2.o level3.o level4.o block.o main.o blocks.o commandinterpreter.o subject.o observer.o window.o textObserver.o graphicobserver.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
