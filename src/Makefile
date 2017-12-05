CXX = g++
CXXFLAGS = -std=c++14 -Wall  -MMD -Werror=vla
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS = block.o cell.o command.o grid.o level.o main.o next.o textdisplay2.o
DEPENDS=${OBJECTS:.o=.d}
	EXEC = quadris

.PHONY : clean

${EXEC} : ${OBJECTS}
	        ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean :
	        rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

.PHONY : clean
