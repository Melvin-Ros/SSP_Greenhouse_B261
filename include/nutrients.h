#pragma once
#include <vector>
#include <iostream>
#include "plant_base.h"


class Nutrients
{
    public:
    static float fertN;
    static float fertP;
    static float fertK;

    //Function that sets growth rate relative to the amounts of nutrients
    void UpdateNutrients(PlantBase &plantBase);
};