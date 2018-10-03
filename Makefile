CC = gcc
CXX = g++
RM = rm -f
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -o


GameOfLife: cell.o field.o main.o
					$(CXX) cell.o field.o main.o $(FLAGS) GameOfLife

cell.o: cell.cpp cell.hpp

field.o: field.cpp field.hpp

main.o: main.cpp

clean:
	$(RM) GameOfLife cell.o field.o main.o
