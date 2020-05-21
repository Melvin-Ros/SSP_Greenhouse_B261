#pragma once
#include <plant_base.h>
#include "water_reservoir.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>



class Greenhouse
{
    public:
    int totalGreenhouseHeight;
    int totalGreenhouseWidth;
    sf::RectangleShape metalBottom;
    sf::RectangleShape dirt;
    sf::RectangleShape glassMiddle;
    sf::RectangleShape glassTop;
    sf::RectangleShape reservoirTop;
    sf::RectangleShape reservoirBottom;
    sf::RectangleShape waterColor;

    //Function that draws greenhouse
	void makeGreenhouse(sf::RenderWindow & window,int totalGreenhouseWidth, int totalGreenhouseHeight);

    private:
    int width = 40;
    int metalHeight = 60;
    float lineThickness = 3.0;

};