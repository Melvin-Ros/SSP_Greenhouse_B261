#pragma once


class WaterTank
{
    public:
    //Sets waterlevel equal to max waterlevel
    void refill();
    //Reduces waterlevel and gives nutrients to the plants
    void updateWaterLevel();

    static float waterLevel;
    static float maxWaterLevel;

    private:

};
