#pragma once
#include <iostream>
#include "cell.hpp"



class Field{

  private:

      float cellSize;
      std::vector< std::vector<Cell> > vectorOfCells;
      std::pair<int,int> fieldDimension;


    public:

        Field(int width, int height, float cellSize);
        Field(std::pair<int,int> fieldDimension, float cellSize);
        Cell getCell(int posX, int posY);
        int getWidth();
        int getHeight();
        void changeCellState(int posX, int posY);
        int analiceNeighbours(int posX, int posY);
        void stepInTime();




};
