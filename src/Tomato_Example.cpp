#include <iostream>
#include <thread>
#include <chrono> 
#include <cstdlib>
#include <ctime>  
#include <vector>

#include "tomato_plant.h"
#include "lemon_plant.h"
#include "greenhouse.h"
#include "nutrients.h"
#include "water_reservoir.h"

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>



int main()
{
    int days = 0;
    WaterTank waterTank;
    Greenhouse greenhouse;
    Nutrients nutrients;
    std::vector<PlantBase> plantBase;
    TomatoPlant tomato1;
	TomatoPlant tomato2;
	LemonPlant lemon3;
    LemonPlant lemon4;
	
    //Sets maxheight, x and y position of the plants
    tomato1.createTomatoPlant(400, 500, 700);
    tomato2.createTomatoPlant(450, 700, 700);
    lemon3.createLemonPlant(550, 900, 700);
    lemon4.createLemonPlant(500, 1100, 700);

	
	plantBase.push_back(tomato1);
	plantBase.push_back(tomato2);
	plantBase.push_back(lemon3);
	plantBase.push_back(lemon4);
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Tomato simulator");
    window.setFramerateLimit(20);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
       
        
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("PLANTS");
        //Create buttom to refill watertank
        if (ImGui::Button("Refill water"))
        {
            waterTank.refill();
        }

        //Displays relevant data
        ImGui::Text("Days: %d",days);
        ImGui::Text("Kalium: %d",int(nutrients.fertK));
        ImGui::Text("Nitrogen: %d",int(nutrients.fertN));
        ImGui::Text("Phosphorus:%d",int(nutrients.fertP));
        ImGui::Text("Waterlevel: %d %c ", int(waterTank.waterLevel/waterTank.maxWaterLevel*100), '%');
        
        {
            waterTank.updateWaterLevel();
            //Simulates one day per update
			for (int i = 0; i < plantBase.size(); i++)
			{
				plantBase[i].grow(1);
                nutrients.UpdateNutrients(plantBase[i]);
		    }
            days ++;
		}
        
        ImGui::End();

        // clear the window with black color
        window.clear(sf::Color::White);
        
        // draw everything here...
        greenhouse.makeGreenhouse(window, 800, 600);

		for (int i = 0; i < plantBase.size(); i++)
		{
			plantBase[i].makeBranches(window);
		}

		ImGui::SFML::Render(window);

        // end the current frame
        window.display();
    }


    return 0;
}