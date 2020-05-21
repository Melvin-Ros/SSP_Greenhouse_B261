#pragma once
#include <plant_base.h>


class LemonPlant : public PlantBase //Det betyder, at vi nedarver fra plantBase ( : )
{
public:
    //Function that sets position of the lemonplant and the basic values (colors, etc.)
    void createLemonPlant(float theMaxHeight, float x, float y);
};