#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp"
#include "field.hpp"

void printPosition(sf::Vector2i mousePos){
  std::cout << "Position X --> " << mousePos.x << " Position Y --> " << mousePos.y << "\n";
}


int main(){


sf::RenderWindow window(sf::VideoMode(480,480), "Game of Life", sf::Style::Close);
float cellSize = 10.0f;

Field gameField(480,480,cellSize);

while (window.isOpen()){
  sf::Event evnt;
  while(window.pollEvent(evnt)){

    switch(evnt.type){
      case sf::Event::Closed:
           window.close();
           break;
      case sf::Event::MouseButtonPressed:
             if (evnt.mouseButton.button == sf::Mouse::Left)
                 std::cout << "Position X --> " << evnt.mouseButton.x << " Position Y --> " << evnt.mouseButton.y << "\n";
             gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y);
             break;
      case sf::Event::KeyPressed:
            if (evnt.key.code == sf::Keyboard::Space)
                gameField.stepInTime();
    }

  }

  window.clear();
  for (int i = 0; i < gameField.getHeight(); i++){
    for (int j = 0; j < gameField.getWidth(); j++){
      window.draw(gameField.getCell(i,j));
    }
  }

  window.display();


}


}
