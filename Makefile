TARGET = foucault.o
SRC = foucault-pendulum.c

CC = gcc
CFLAGS = -O3 -march=native -ffast-math -funroll-loops -falign-functions=64
LIBS = -lm -lncurses

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean: 
	rm -f $(TARGET)
