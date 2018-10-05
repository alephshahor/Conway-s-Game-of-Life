CC = gcc
CXX = g++
RM = rm -f
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -o


GameOfLife: cell.o field.o gameScreen.o firstScreen.o main.o
					$(CXX) cell.o field.o gameScreen.o firstScreen.o main.o $(FLAGS) GameOfLife

cell.o: cell.cpp cell.hpp

field.o: field.cpp field.hpp

gameScreen.o: gameScreen.hpp gameScreen.cpp

firstScreen.o: firstScreen.hpp firstScreen.cpp

main.o: main.cpp

clean:
	$(RM) GameOfLife cell.o field.o screen.o gameScreen.o firstScreen.o main.o
