# Makefile for Spaceship Game

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = spaceship_game

all: $(TARGET)

$(TARGET): main.o #game.o player.o bullet.o enemy.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o $(LDFLAGS) 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)