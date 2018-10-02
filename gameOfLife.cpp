#include <SFML/Graphics.hpp>
#include <vector>

#include "cell.hpp"


int main(){

sf::RenderWindow window(sf::VideoMode(480,480), "Game of Life", sf::Style::Close);
std::vector<Cell> vectorOfCells;
float cellSize = 10.0f;


for (int i = 0; i < 480 / cellSize; i++){
    for (int j = 0; j < 480 / cellSize; j++){
      vectorOfCells.push_back(Cell(false,cellSize,10.0f*j, 10.0f*i));
    }
}

while (window.isOpen()){
  sf::Event evnt;
  while(window.pollEvent(evnt)){

    switch(evnt.type){
      case sf::Event::Closed:
           window.close();
           break;
    }
  }

  //window.clear();
  for (int i = 0; i < vectorOfCells.size(); i++){
      window.draw(vectorOfCells[i]);
      window.display();
  }

}


}
