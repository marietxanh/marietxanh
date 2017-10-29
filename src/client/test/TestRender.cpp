/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "TestRender.h"
#define LANDS_STR "Lands"
#define BUILDINGS_STR "Buildings"

using namespace std;
using namespace render;
using namespace sf;

void TestRender::testRender(string file_name)
{
    /*creation de la fenetre et de ses dimensions*/
    
    
    Layer lands(file_name, "Lands");
    Layer buildings(file_name, "Buildings");
    
    std::cout << "Layers loaded" << std::endl;
    
    lands.setSurface();
    
    cout << "Lands ready !" << endl;
    
    buildings.setSurface();
    
    cout << "Buildings ready !" << endl;
    
    RenderWindow window(VideoMode(size_t(lands.getWidth()*lands.getTile_width()), size_t(lands.getHeight()*lands.getTile_height())), "TestRender");
    //window.setFramerateLimit(30);
    cout << "Ouverture fenetre" << endl;
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(lands.getSurface());
        window.draw(buildings.getSurface());
        window.display();
    }
   
}

