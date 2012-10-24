CC			=	g++
CFLAGS			+=	-W -Wall -Werror -DD_SDL -DD_ERRORS_ON -I/include
LDFLAGS			+=	-Llib -l2D -lSDL -lSDL_ttf -lcmc -lcste

EXEC			=	id_mygame
SRC			=	$(wildcard *.cpp)
OBJ			=	$(SRC:.cpp=.o)

all			:	$(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

id_mygame		:	$(OBJ)
			$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

.PHONY: clean distclean rebuild

clean			:
			rm -rf $(OBJ)

distclean		:	clean
			rm -rf $(EXEC)

rebuild			:	distclean all

debug		:	CFLAGS += -g3
debug		:	rebuild
