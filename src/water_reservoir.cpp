#include "water_reservoir.h"
#include "nutrients.h"


float WaterTank::waterLevel = 600 + 60 + 40 + 40;
float WaterTank::maxWaterLevel = 0.0;

//Sets waterlevel equal to max waterlevel
void WaterTank::refill()
{
    waterLevel = maxWaterLevel;
}


//Reduces waterlevel and gives nutrients to the plants
void WaterTank::updateWaterLevel()
{
	Nutrients nutrients;
	if(waterLevel >= 0)
    {
	    waterLevel -=3;
        if (nutrients.fertP < 100)
        {
            nutrients.fertP += 20;
        }
        if (nutrients.fertN < 300)
        {
	        nutrients.fertN += 25;
        }
		if (nutrients.fertK < 100)
        {
			nutrients.fertK += 13;
		}
	    
	}
}