#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell : public sf::Drawable{

  private:

    bool alive;
    float cellSize;
    std::pair<int,int> position; // pair<posX,posY>
    sf::RectangleShape cellDrawable;
    sf::Texture aliveTexture;
    sf::Texture deathTexture;

    // This function allows us to draw the cell using a nicer syntax
    // window.draw(cell) instead of cell.draw(window).
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  public:

    // Constructors

    Cell(bool alive, float cellSize, std::pair<int,int> position);
    Cell(bool alive, float cellSize, int posX, int posY);

    // Setters

    void bringToLife();
    void returnToDeath();
    void setPosition(int posX, int posY);
    void setPosition(std::pair<int,int> position);

    // Getters

    bool isAlive();
    std::pair<int,int> getPosition();


    // This function sets the correspond texture depending on whether the
    // cell is dead or alive.
    void setTexture();


};
