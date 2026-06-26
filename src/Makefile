# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g

# Linker flags (SQLite usually requires pthread and dl on Linux/Unix)
LDFLAGS = -pthread -ldl -lm 

# Name of the final executable
TARGET = bank_files

SQLITE_OBJ = ../../sqlite-src-3510300/sqlite3.o

# List of object files to generate
OBJS = main.o input_file_reader.o $(SQLITE_OBJ)

# Default target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to compile main.c (depends on the header file)
main.o: main.c input_file_reader.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile input_file_reader.c (depends on the header file)
input_file_reader.o: input_file_reader.c input_file_reader.h
	$(CC) $(CFLAGS) -c input_file_reader.c

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
