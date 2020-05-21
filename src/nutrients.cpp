#include "nutrients.h"
#include "plant_base.h"

//N & K for growth of plant, 300 & 100
//P for growth of fruit, 100

float Nutrients::fertK = 1;
float Nutrients::fertP = 1;
float Nutrients::fertN = 1;

//Function that sets growth rate relative to the amounts of nutrients
void Nutrients::UpdateNutrients(PlantBase &plantBase)
{	 
    plantBase.growth_rate = plantBase.defaultGrowthRate * (fertK + fertN) / 400;
    
    plantBase.plantGrowthRate = plantBase.defaultPlantGrowthRate * fertP / 100;
}