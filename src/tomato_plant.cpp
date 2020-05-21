#include "tomato_plant.h"

void TomatoPlant::createTomatoPlant(float theMaxHeight, float x, float y)
{
    sf::Vector2f position;
    position.x = x;
    position.y = y;

    // Function sets the following variables:
    // numBranches, startBranch, branchLength, numFruitsPerBranch, growthRateStalk, fruitGrowthRate, fruitDiameter, RotationRight, RotationLeft, 
    // kalium, phosphor, nitrogen, fruitColor, stalkColor, position.
    setPlantVariables(10, 50, 75, 3, 1.5, 0.1, 5.0, 60, 300, 1.0, 1.0, 2.0, sf::Color::Red, sf::Color::Green, position);
    plantSetup(theMaxHeight);
}