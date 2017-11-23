CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -MMD -Werror=vla
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS = cell.o grid.o main.o textdisplay.o window.o graphicsdisplay.o
DEPENDS=${OBJECTS:.o=.d}
	EXEC = a4q5

.PHONY : clean

${EXEC} : ${OBJECTS}
	        ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean :
	        rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

.PHONY : clean
