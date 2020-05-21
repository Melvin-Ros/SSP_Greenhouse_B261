#include "lemon_plant.h"

//Function that sets position of the lemonplant and the basic values (colors, etc.)
void LemonPlant::createLemonPlant(float theMaxHeight, float x, float y)
{
    sf::Vector2f position;
    position.x = x;
    position.y = y;

    // Function sets the following variables:
    // numBranches, startBranch, branchLength, numFruitsPerBranch, growthRateStalk, fruitGrowthRate, fruitDiameter, RotationRight, RotationLeft, 
    // kalium, phosphor, nitrogen, fruitColor, stalkColor, position.
    setPlantVariables(15, 300, 100, 3, 0.5, 0.1, 5.0, 60, 300, 0.5, 1.0, 2.0, sf::Color::Yellow, sf::Color(0, 100, 0), position);
    plantSetup(theMaxHeight);
}