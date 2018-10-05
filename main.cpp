#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp"
#include "field.hpp"
#include "cScreen.hpp"
#include "gameScreen.hpp"
#include "firstScreen.hpp"


int main(){


sf::RenderWindow window(sf::VideoMode(480,480), "Game of Life", sf::Style::Close);

std::vector<cScreen*> Screens;

firstScreen screen01;
gameScreen screen02;
Screens.push_back(&screen01);
Screens.push_back(&screen02);

int screen = 0;

while (screen != -1){
  screen = Screens[screen] -> Run(window);
}


}
