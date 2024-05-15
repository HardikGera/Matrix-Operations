
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
EXECUTABLE = math_matrix
SRC = math_matrix.c
OBJSRC = functions.c
OBJ = functions.o
HLP = functions.h

$(EXECUTABLE): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRC) $(OBJ)
$(OBJ): $(OBJSRC) $(HLP)
	$(CC) -c $(OBJSRC) $(CFLAGS) -o $(OBJ)
clean:
	rm -f math_matrix functions.o
