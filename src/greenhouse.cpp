#include "greenhouse.h"
#include "plant_base.h"
#include "nutrients.h"
#include "water_reservoir.h"

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>




void Greenhouse::makeGreenhouse(sf::RenderWindow & window, int totalGreenhouseWidth, int totalGreenhouseHeight)
{
    WaterTank waterTank;

    //Sets variables for middleglass
    sf::Vector2f middleGlass;
    middleGlass.x = totalGreenhouseWidth;
    middleGlass.y = totalGreenhouseHeight;
    glassMiddle.setSize(middleGlass);
    glassMiddle.setOutlineThickness(lineThickness);
    glassMiddle.setOutlineColor(sf::Color::Black);
    glassMiddle.setFillColor(sf::Color::Transparent);
    
    //Sets variables for topglass
    sf::Vector2f topGlass;
    topGlass.x = middleGlass.x;
    topGlass.y = width;
    glassTop.setSize(topGlass);
    glassTop.setOutlineThickness(lineThickness);
    glassTop.setOutlineColor(sf::Color::Black);
    glassTop.setFillColor(sf::Color::Transparent);
    
    //Sets variables for top of water reservoir
    sf::Vector2f topReservoir;
    topReservoir.x = width;
    topReservoir.y = width;
    reservoirTop.setSize(topReservoir);
    reservoirTop.setOutlineThickness(lineThickness);
    reservoirTop.setOutlineColor(sf::Color::Black);
    reservoirTop.setFillColor(sf::Color::Transparent);
    
    //Sets variables for metal bottom
    sf::Vector2f bottomMetal;
    bottomMetal.x = middleGlass.x;
    bottomMetal.y = metalHeight;
    metalBottom.setSize(bottomMetal);
    metalBottom.setOutlineThickness(lineThickness);
    metalBottom.setOutlineColor(sf::Color::Black);
    metalBottom.setFillColor(sf::Color(105,105,105)); //128 i stedet måske
    
    //Sets max waterlevel and variables for bottom reservoir
    waterTank.maxWaterLevel = 600 + 60 + 40 + 40;
    sf::Vector2f bottomReservoir;
    bottomReservoir.x = width;
    bottomReservoir.y = -waterTank.waterLevel;
    
    reservoirBottom.setSize(bottomReservoir);
    reservoirBottom.setFillColor(sf::Color::Blue);
   
    //Makes reservoir transparent when waterlevel reduces
    sf::Vector2f vecWater;
    vecWater.x = width;
    vecWater.y = middleGlass.y + bottomMetal.y + width;
    waterColor.setSize(vecWater);
    waterColor.setOutlineThickness(lineThickness);
    waterColor.setOutlineColor(sf::Color::Black);
    waterColor.setFillColor(sf::Color::Transparent);

    //Sets variables for dirt
    sf::Vector2f vecDirt;
    vecDirt.x = middleGlass.x-3.0;
    vecDirt.y = width;
    dirt.setSize(vecDirt);
    dirt.setOutlineThickness(lineThickness);
    dirt.setOutlineColor(sf::Color::Black);
    dirt.setFillColor(sf::Color(130,65,0));
    

    //Sets positions of greenhouse pieces:
    glassMiddle.setPosition(400, 80);
    dirt.setPosition(403, 680);
    glassTop.setPosition(400, 40);
    reservoirTop.setPosition(360, 40);
    reservoirBottom.setPosition(360, 780);
    metalBottom.setPosition(400, 720);
    waterColor.setPosition(360, 80);

    //Draws greenhouse:
    window.draw(glassMiddle);
    window.draw(glassTop);
	window.draw(reservoirTop);
    window.draw(metalBottom);
    window.draw(dirt);
    window.draw(reservoirBottom);
    window.draw(waterColor);
}