#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>



class PlantBase
{
public:
    //Function that sets plant variables
    void setPlantVariables( 
        int mnumBranches,
        int mbranchStart,
        int mbranchLength,
        int mnumPlantsPerBranch,
        float mdefaultGrowthRate,
        float mdefaultPlantGrowthRate,
        float mfruitDiameter,
        float mplantRotationRight,
        float mplantRotationLeft,
        float mkaliumConsumption,
        float mphosphorusConsumption,
        float mnitrogenConsumption,
        sf::Color mcolorFruit,
        sf::Color mcolorStalk,
        sf::Vector2f mstalkStartPosition);

    //Function that grows according to the days
	void grow(int days) ;
    //Function that draws branches
	void makeBranches(sf::RenderWindow & window);

	double growth_rate{1.5};
	double plantGrowthRate{0.2};
    float defaultGrowthRate = 1.5;
    float defaultPlantGrowthRate = 0.1;
    float kaliumConsumption = 1;
    float phosphorusConsumption = 1;
    float nitrogenConsumption = 2;

    //Function that randomizes the branches and puts fruit on them
	void plantSetup(float theMaxHeight);

    //The start position of all the branches along the stalk
    std::vector<float> branchStartPosition;
    double height = 5.0;

private:
    sf::RectangleShape plantStalk;
    //Variables for each fruit
    std::vector<sf::CircleShape> plants;
	std::vector<float> fruitSize;
	std::vector<bool> startGrowingFruit;
    //Variables for each branch
    std::vector<sf::RectangleShape> branch;
    std::vector<float> branchHeight;

protected:
    int stalkHeight = 400;
    int numBranches = 10;
    int branchStart = 50;
    int branchLength = 75;
    int numPlantsPerBranch = 3;
    float maxHeight = 1.0;
    float fruitDiameter = 5.0;
    float plantRotationRight = 60;
    float plantRotationLeft = 300;
    sf::Color colorFruit = sf::Color::Red;
    sf::Color colorStalk = sf::Color::Green;
    sf::Vector2f stalkStartPosition;
};