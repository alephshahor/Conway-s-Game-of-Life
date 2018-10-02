#include "cell.hpp"


Cell::Cell(bool alive, float cellSize, std::pair<int,int> position):
      alive(alive),
      cellSize(cellSize),
      position(position)
      {
        aliveTexture.loadFromFile("black.png");
        deathTexture.loadFromFile("white.png");
        cellDrawable.setSize(sf::Vector2f(cellSize,cellSize));
        cellDrawable.setPosition(position.first, position.second);
      }

Cell::Cell(bool alive, float cellSize, int posX, int posY){
      this -> alive = alive;
      this -> cellSize = cellSize;
      position = std::make_pair(posX, posY);

      aliveTexture.loadFromFile("black.png");
      deathTexture.loadFromFile("white.png");
      cellDrawable.setSize(sf::Vector2f(cellSize,cellSize));
      cellDrawable.setPosition(posX, posY);
}

void Cell::bringToLife(){
      alive = true;
}

void Cell::returnToDeath(){
      alive = false;
}

void Cell::setPosition(int posX, int posY){
     position.first = posX;
     position.second = posY;
}

void Cell::setPosition(std::pair<int,int> position){
    this -> position.first = position.first;
    this -> position.second = position.second;
}

void Cell::setTexture(){
  if (alive)
  cellDrawable.setTexture(&aliveTexture, true);
  else
  cellDrawable.setTexture(&deathTexture);
}

bool Cell::isAlive(){
    return alive;
}

std::pair<int,int> Cell::getPosition(){
    return position;
}


void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(cellDrawable);
}
