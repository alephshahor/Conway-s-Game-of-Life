#include "firstScreen.hpp"

int firstScreen::Run(sf::RenderWindow& window){

sf::RectangleShape mainScreen(sf::Vector2f(480.0f,480.0f));
sf::Texture mainScreenTexture;
mainScreenTexture.loadFromFile("./art/conwayMainScreen.png");
mainScreen.setTexture(&mainScreenTexture);

bool running = true;

while (running){
  sf::Event evnt;
  while(window.pollEvent(evnt)){

    switch(evnt.type){
      case sf::Event::Closed:
           window.close();
           return -1;
           break;
      case sf::Event::KeyPressed:
            if (evnt.key.code == sf::Keyboard::Space)
                running = false;
            break;
    }

  }

  window.clear();
  window.draw(mainScreen);
  window.display();

  }

  return 1;

}
