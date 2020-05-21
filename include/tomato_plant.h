#pragma once
#include <plant_base.h>


class TomatoPlant : public PlantBase //Det betyder, at vi nedarver fra plantBase ( : )
{
public:
    //Function that sets position of the tomatoplant and the basic values (colors, etc.)
    void createTomatoPlant(float theMaxHeight, float x, float y);
};
