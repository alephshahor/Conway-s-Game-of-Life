#include "firstScreen.hpp"

int firstScreen::Run(sf::RenderWindow& window){

sf::RectangleShape playButton(sf::Vector2f(100.0f,20.0f));
playButton.setPosition(190,240);
bool running = true;

while (running){
  sf::Event evnt;
  while(window.pollEvent(evnt)){

    switch(evnt.type){
      case sf::Event::Closed:
           window.close();
           break;
      case sf::Event::KeyPressed:
            if (evnt.key.code == sf::Keyboard::Space)
                running = false;
            break;
    }

  }

  window.clear();
  window.draw(playButton);
  window.display();

  }

  return 1;

}
