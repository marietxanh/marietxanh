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
    

    for(int i(0); i < lands.getWidth(); i++)
    {
        for(int j (0); lands.getHeight(); j++)
        {
            lands.getSurface().setQuadPosition(lands.getSurface().getQuad(i, j), lands.getWidth(),
                    lands.getHeight(), lands.getTile_width(), buildings.getTile_height(),
                    lands.getTileSet()->getTile(lands.getSurface().getLayerArray(i , j))->getWidth(),
                    lands.getTileSet()->getTile(lands.getSurface().getLayerArray(i , j))->getWidth());
            lands.getSurface().setQuadTextureCoordinates(lands.getSurface().getQuad(i, j),
                    lands.getTileSet()->getTile(lands.getSurface().getLayerArray(i , j))->getWidth(),
                    lands.getTileSet()->getTile(lands.getSurface().getLayerArray(i , j))->getWidth());
        }
    }
    
    for(int i(0); i < buildings.getWidth(); i++)
    {
        for(int j (0); buildings.getHeight(); j++)
        {   
            buildings.getSurface().setQuadPosition(buildings.getSurface().getQuad(i, j), buildings.getWidth(),
                    buildings.getHeight(), buildings.getTile_width(), buildings.getTile_height(),
                    buildings.getTileSet()->getTile(buildings.getSurface().getLayerArray(i , j))->getWidth(),
                    buildings.getTileSet()->getTile(buildings.getSurface().getLayerArray(i , j))->getWidth());
            buildings.getSurface().setQuadTextureCoordinates(buildings.getSurface().getQuad(i, j),
                    buildings.getTileSet()->getTile(buildings.getSurface().getLayerArray(i , j))->getWidth(),
                    buildings.getTileSet()->getTile(buildings.getSurface().getLayerArray(i , j))->getWidth());
        }
    }
   
    
    RenderWindow window(sf::VideoMode(size_t(lands.getWidth()*lands.getTile_width()), size_t(lands.getHeight()*lands.getTile_height())), "TestRender");
    window.setFramerateLimit(30);
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

        // on dessine le niveau
        window.clear();
        window.draw(lands.getSurface());
        window.draw(buildings.getSurface());
        window.display();
    }
   
}

