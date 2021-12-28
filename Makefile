CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -O3
EXEC = cube
OBJECTS = face.o cube.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}