#include "plant_base.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "nutrients.h"

//Function that sets plant variables
void PlantBase::setPlantVariables( 
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
        sf::Vector2f mstalkStartPosition) 
    {
        numBranches = mnumBranches;
        branchStart = mbranchStart;
        branchLength = mbranchLength;
        numPlantsPerBranch = mnumPlantsPerBranch;
        defaultGrowthRate = mdefaultGrowthRate;
        defaultPlantGrowthRate = mdefaultGrowthRate;
        fruitDiameter = mfruitDiameter;
        plantRotationRight = mplantRotationRight;
        plantRotationLeft = mplantRotationLeft;
        kaliumConsumption = mkaliumConsumption;
        phosphorusConsumption = mphosphorusConsumption;
        nitrogenConsumption = mnitrogenConsumption;
        colorFruit = mcolorFruit;
        colorStalk = mcolorStalk;
        stalkStartPosition = mstalkStartPosition;
    }

    //Function that randomizes the branches and puts fruit on them
    void PlantBase::plantSetup(float theMaxHeight)
    {
        std::default_random_engine generator;

        maxHeight = theMaxHeight;
        plantStalk.setPosition(stalkStartPosition);
        //Randomize rotation of branches (left or right) and their position
        for (int i = 0; i < numBranches; i++)
        {
            sf::RectangleShape branchTemp;
            {
                std::uniform_int_distribution<int> distribution(0,10);
                int chance = distribution(generator);
                if (chance > 5)
                {
                    branchTemp.setRotation(plantRotationLeft);
                }
                else
                {
                    branchTemp.setRotation(plantRotationRight);
                }
            }
            branch.push_back(branchTemp);
            branchHeight.push_back(0);
            {
                std::uniform_int_distribution<int> distribution(branchStart, maxHeight);
                branchStartPosition.push_back(distribution(generator));
                //Places fruits on the branches
                for (int j = 0; j <= numPlantsPerBranch; j++)
                {
                    sf::CircleShape plantTemp;
                    plants.push_back(plantTemp);
				    fruitSize.push_back(0);
                    startGrowingFruit.push_back(false);
			    }
            }
        }
    }

//Function that grows according to the days
void PlantBase::grow(int days)
{
    sf::Vector2f stalkSize;
    stalkSize.x = 8;
    stalkSize.y = -height;
    plantStalk.setSize(stalkSize);
    plantStalk.setFillColor(colorStalk);

	
	//increase height of stalk and branches
    if (height < maxHeight)
    {
        height = height + days * growth_rate;
    }
       plantStalk.setPosition(stalkStartPosition);
        //Update size of stalk, branches and plant relative to the amount of nutrients
        Nutrients nutrients;
        for (int i = 0; i < numBranches; i++)
        {
            for(int j = 1; j <= numPlantsPerBranch; j++)
            {
                if(startGrowingFruit[i+j] == true &&    fruitSize[j+i] <= 5)
                {
                fruitSize[i+j] += days*plantGrowthRate;
                    //Reduces amount of phosphorus when fruits grow
                    if (nutrients.fertP>0)
                    {
                        nutrients.fertP -= phosphorusConsumption;
                    }
                }
            }

            if (branchHeight[i] <= branchLength && height > branchStartPosition[i])
            {
                branchHeight[i] = branchHeight[i] + days * growth_rate;
                //Reduces amount of kalium and nitrogen when each branch grow
                if (nutrients.fertK>0)
                    {
                        nutrients.fertK -= kaliumConsumption;
                    }
                if (nutrients.fertN>0)
                    {
                        nutrients.fertN -= nitrogenConsumption;
                    }
                std::cout << branchHeight[i] << std::endl;

                sf::Vector2f size;
                size.x = 3.0;
                size.y = -branchHeight[i];
                branch[i].setSize(size);
                branch[i].setFillColor(colorStalk);
             
			}
		}

}

//Function that draws branches
void PlantBase::makeBranches(sf::RenderWindow & window)
{
    window.draw(plantStalk);

    for (int i = 0; i < numBranches; i++)
        {
            //Draws branch if the stalk height is larger than branch start position
            if (height >= branchStartPosition[i])
            {
                window.draw(branch[i]);
                branch[i].setPosition(stalkStartPosition.x, stalkStartPosition.y-branchStartPosition[i]);

                //Draws fruits on the branches
                for (int j = 1; j <= numPlantsPerBranch; j++)
                {
                    plants[j].setRotation(branch[i].getRotation());
                    //Draws fruit on the right side relative to the branch height
					if (branch[i].getRotation() == plantRotationRight)
                    {
                        if (branchHeight[i] > 24*j)
                        {
							plants[j].setPosition(branch[i].getPosition().x + 20 * j, branch[i].getPosition().y - 11.5 * j+2);
                            
							plants[j].setRadius(fruitSize[i+j]);
                            startGrowingFruit[i+j] = true;
                            plants[j].setFillColor(colorFruit);
                           
                            window.draw(plants[j]);
                        }
                    }
                    //Draws fruit on the left side relative to the branch height
                    else
                    {
                        if (branchHeight[i] > 24*j)
                        {
                            plants[j].setPosition(branch[i].getPosition().x-20*j, branch[i].getPosition().y-11.5*j+10);
                            plants[j].setRadius(fruitSize[i+j]);
                            startGrowingFruit[i+j] = true;
                            plants[j].setFillColor(colorFruit);
                            
                            window.draw(plants[j]);
                        }
                    }
                }
            }
        }

}