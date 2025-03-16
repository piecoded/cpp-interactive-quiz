CC = g++
CFLAGS = -std=c++17 -Wall -g
INCLUDES = -Iinclude
SOURCES = src/main.cpp src/quiz_validator.cpp src/parse_questions.cpp src/quiz_utils.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = bin/quiz.exe  # Use .exe for Windows

all: bin $(EXECUTABLE)

# Create bin directory if it doesn't exist
bin:
	mkdir -p bin

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(EXECUTABLE)

.PHONY: all clean
