#include "gameScreen.hpp"

int gameScreen::Run(sf::RenderWindow& window){

  float cellSize = 10.0f;

  Field gameField(480,480,cellSize);
  gameField.stepInTime();

  bool isPaused = false;
  bool running = true;

  while (running){
    sf::Event evnt;
    while(window.pollEvent(evnt)){

      switch(evnt.type){
        case sf::Event::Closed:
             window.close();
             break;
        case sf::Event::MouseButtonPressed:
               if ((evnt.mouseButton.button == sf::Mouse::Left) && (isPaused))
               gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y);
               break;
        case sf::Event::KeyPressed:
              if (evnt.key.code == sf::Keyboard::Space)
                  if (isPaused)
                      isPaused = false;
                  else isPaused = true;
              if (evnt.key.code == sf::Keyboard::Escape)
                  running = false ;
              break;
      }

    }

    if (!isPaused)
    gameField.stepInTime();

    window.clear();
    for (int i = 0; i < gameField.getHeight(); i++){
      for (int j = 0; j < gameField.getWidth(); j++){
        window.draw(gameField.getCell(i,j));
      }
    }

    window.display();



  }


  return -1;

}
