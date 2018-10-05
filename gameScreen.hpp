#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp"
#include "field.hpp"
#include "cScreen.hpp"

class gameScreen : public cScreen {


private:
public:
    virtual int Run(sf::RenderWindow& window);

};
