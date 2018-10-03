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



/* I would like to optimice this process and make it
   more simple */

int Field::analiceNeighbours(int posX, int posY){


  int numberOfNeighbours = 0;
  int maxPosX = (fieldDimension.first / cellSize) - 1;
  int maxPosY = (fieldDimension.second / cellSize) - 1;

  if (posY == 0){

    if (posX == 0){

      for (int i = posY; i <= posY + 1; i++){
        for (int j = posX; j <= posX +1; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else if (posX == maxPosX){

      for (int i = posY; i <= posY + 1; i++){
        for (int j = posX - 1; j <= posX; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else{

      for (int i = posY; i <= posY + 1; i++){
        for (int j = posX - 1; j <= posX + 1; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }

  }else if (posY == maxPosY){

    if (posX == 0){

      for (int i = posY - 1; i <= posY; i++){
        for (int j = posX; j <= posX +1; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else if (posX == maxPosX){

      for (int i = posY - 1; i <= posY; i++){
        for (int j = posX - 1; j <= posX; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else{

      for (int i = posY - 1; i <= posY; i++){
        for (int j = posX - 1; j <= posX + 1; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }

  }else{


    if (posX == 0){

      for (int i = posY - 1; i <= posY  + 1; i++){
        for (int j = posX; j <= posX +1; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else if (posX == maxPosX){

      for (int i = posY - 1; i <= posY + 1; i++){
        for (int j = posX - 1; j <= posX; j++){

            if(vectorOfCells[i][j].isAlive())
              numberOfNeighbours++;
            }
          }

    }else{

      for (int i = posY - 1; i <= posY + 1; i++){
        for (int j = posX - 1; j <= posX + 1; j++){
            if(vectorOfCells[i][j].isAlive()){
              numberOfNeighbours++;

              if ((j == posX) && (i == posY) && (vectorOfCells[i][j].isAlive()) ){
                numberOfNeighbours--;
              }

            }
            }
          }

    }


  }




  return numberOfNeighbours;

}

void Field::stepInTime(){

  std::vector< std::vector <int> > vectorOfNeighbours;

  for (int i = 0; i < fieldDimension.second / cellSize; i++){

    std::vector <int> vOfNeighbours;

      for (int j = 0; j < fieldDimension.first / cellSize; j++){

           int numberOfNeighbours = analiceNeighbours(j,i);
           vOfNeighbours.push_back(numberOfNeighbours);


      }

      vectorOfNeighbours.push_back(vOfNeighbours);
    }


  for (int i = 0; i < fieldDimension.second / cellSize; i++){
      for (int j = 0; j < fieldDimension.first / cellSize; j++){

          int numberOfNeighbours = vectorOfNeighbours[i][j];

          if (numberOfNeighbours < 2){
            // Dies of underpopulation
            if (vectorOfCells[i][j].isAlive()){
                vectorOfCells[i][j].returnToDeath();
                vectorOfCells[i][j].setTexture();
            }
          }else if (numberOfNeighbours > 3){
            // Dies of overpopulation
            if (vectorOfCells[i][j].isAlive()){
                vectorOfCells[i][j].returnToDeath();
                vectorOfCells[i][j].setTexture();
            }
          }else if (numberOfNeighbours == 3){
            // If it's dead it becomes alive.
            if (!vectorOfCells[i][j].isAlive()){
                 vectorOfCells[i][j].bringToLife();
                 vectorOfCells[i][j].setTexture();
            }
          }

          }


      }
  }
