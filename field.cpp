#include "field.hpp"

Field::Field(int width, int height, float cellSize):
       cellSize(cellSize),
       vectorOfCells(),
       fieldDimension(std::make_pair(width,height))
       {

         for (int i = 0; i < height / cellSize; i++){
             std::vector<Cell> vCells;
             for (int j = 0; j < width / cellSize; j++){
               vCells.push_back(Cell(false,cellSize,10.0f*j, 10.0f*i));
             }
               vectorOfCells.push_back(vCells);
         }

         for (int i = 0; i < height / cellSize; i++){
             for (int j = 0; j < width / cellSize; j++){
               vectorOfCells[i][j].setTexture();
             }
         }

       }

Field::Field(std::pair<int,int> fieldDimension, float cellSize):
        cellSize(cellSize),
        vectorOfCells(),
        fieldDimension(fieldDimension)
        {

          for (int i = 0; i < fieldDimension.second / cellSize; i++){
              std::vector<Cell> vCells;
              for (int j = 0; j < fieldDimension.first / cellSize; j++){
                vCells.push_back(Cell(false,cellSize,10.0f*j, 10.0f*i));
              }
                vectorOfCells.push_back(vCells);
          }

          /* This is necessary because when you use push_back you're actually
          creating a copy of the object you're inserting so you lose the
          texture reference*/
          for (int i = 0; i < fieldDimension.second / cellSize; i++){
              for (int j = 0; j < fieldDimension.first / cellSize; j++){
                vectorOfCells[i][j].setTexture();
              }
          }


        }

Cell Field::getCell(int posX, int posY){
        return vectorOfCells[posY][posX];
}

int Field::getWidth(){
  return fieldDimension.first / cellSize;
}

int Field::getHeight(){
  return fieldDimension.second / cellSize;
}

void Field::changeCellState(int posX, int posY){

    posX /= cellSize;
    posY /= cellSize;

  if (vectorOfCells[posY][posX].isAlive())
      vectorOfCells[posY][posX].returnToDeath();
  else vectorOfCells[posY][posX].bringToLife();

  vectorOfCells[posY][posX].setTexture();
}


int Field::analiceNeighbours(int posX, int posY){

  std::cout << "I made it here!\n";

  int numberOfNeighbours = 0;
  int maxPosX = (fieldDimension.first / cellSize) - 1;
  int maxPosY = (fieldDimension.second / cellSize) - 1;

  if (posX == 0 && posY == 0){
    std::cout << "I must arrive here\n";
    for (int i = posY; i <= posY + 1; i++){
      for (int j = posX; j <= posX +1; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX == 0 && posY == maxPosY){
    for (int i = posY - 1; i <= posY; i++){
      for (int j = posX; j <= posX +1; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX == 0 && posY != maxPosY){
    for (int i = posY - 1; i <= posY + 1; i++){
      for (int j = posX; j <= posX +1; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX == maxPosX && posY == 0){
    for (int i = posY; i <= posY + 1; i++){
      for (int j = posX - 1; j <= posX; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX == maxPosX && posY == maxPosY){
    for (int i = posY - 1; i <= posY; i++){
      for (int j = posX - 1; j <= posX; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX == maxPosX && posY != 0){
    for (int i = posY - 1; i <= posY + 1; i++){
      for (int j = posX - 1; j <= posX; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else if (posX != maxPosX && posY != maxPosY){

    std::cout << "1\n";

    for (int i = posY - 1; i <= posY + 1; i++){
      for (int j = posX - 1 ; j <= posX +1; j++){

          if(vectorOfCells[i][j].isAlive())
            numberOfNeighbours++;

      }
    }
  }else

  std::cout << "I WENT OUT\n";

  return numberOfNeighbours;

}

void Field::stepInTime(){



  for (int i = 0; i < fieldDimension.second / cellSize; i++){
      for (int j = 0; j < fieldDimension.first / cellSize; j++){

          int numberOfNeighbours = analiceNeighbours(i,j);

          if (numberOfNeighbours < 2){
            // Dies of underpopulation
            if (vectorOfCells[i][j].isAlive()){
                vectorOfCells[i][j].returnToDeath();
            }
          }else if (numberOfNeighbours > 3){
            // Dies of overpopulation
            if (vectorOfCells[i][j].isAlive()){
                vectorOfCells[i][j].returnToDeath();
            }
          }else if (numberOfNeighbours == 3){
            // If it's dead it becomes alive.
            if (!vectorOfCells[i][j].isAlive()){
                 vectorOfCells[i][j].bringToLife();
            }
          }

          }


      }
  }
