#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

int main(){


sf::RenderWindow window(sf::VideoMode(512,512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
sf::RectangleShape player(sf::Vector2f(10.0f,10.0f));
//player.setFillColor(sf::Color::Red);
//player.setOrigin(50.0f, 50.0f);
sf::Texture playerTexture;
playerTexture.loadFromFile("grass.png");
player.setTexture(&playerTexture);


while(window.isOpen()){

  sf::Event evnt;
  while(window.pollEvent(evnt)){

    switch(evnt.type){
      case sf::Event::Closed:
           window.close();
           break;
    }

    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player.move(-1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.move(1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player.move(0.0f, -1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.move(0.0f, 1.0f);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
      }*/


    window.clear();
    window.draw(player);
    window.display();

  }



}


}
