CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = cc3k.o character.o enemy.o floor.o item.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
