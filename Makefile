# Makefile for Spaceship Game

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = spaceship_game

all: $(TARGET)

$(TARGET): main.o
	$(CXX) -o $(TARGET) main.o $(LDFLAGS) 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f main main.o