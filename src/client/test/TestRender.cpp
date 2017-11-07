#include "TestRender.h"

using namespace sf;
using namespace render;

void TestRender::testRender()
{
	char clands[] = "Lands";
	char cbuildings[] = "Buildings";
	char text_file_name[] = "res/test_render.txt";
        /*on cree deux plans
         les terrains qui ne seront jamais modifies
         les batiments qui peuvent changer de couleur
         en fonction de qui les possede
         ceci est dans l'objectif de modifier plus facilement
         la texture d'un sprite*/
	Layer buildings(text_file_name, cbuildings);        
	Layer lands(text_file_name, clands);
	int width, height;
	width = lands.getWidth() * lands.getTile_width();
	height = lands.getHeight() * lands.getTile_height();
        sf::Texture texttest[2];
        sf::Sprite sprittest[2];
        texttest[0].loadFromFile("res/advance_wars_sprites_lands/plain.png");
        texttest[1].loadFromFile("res/advance_wars_sprites_lands/mountain/small_mountain.png");
        sprittest[0].setPosition(sf::Vector2f(0, 0));
        sprittest[1].setPosition(sf::Vector2f(16, 0));
        sprittest[0].setTexture(texttest[0]);
        sprittest[1].setTexture(texttest[1]);
        //lands.affiche();
	sf::RenderWindow window(sf::VideoMode(width, height), "RenderWindow");
        window.setFramerateLimit(30);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for(int i(0); i < lands.getHeight(); i++)
		{
			for(int j(0); j < lands.getWidth(); j++)
			{
                            /*on dessine dans l'ordre les differents "calques"
                             d'abord les terrains et ensuite les batiments*/
                            if(lands.getLayer_array(i, j) > 0)
				window.draw(lands.getSprite(i, j));
                            if(buildings.getLayer_array(i, j) > 0)
				window.draw(buildings.getSprite(i, j));
			}
                        
		}
                window.draw(sprittest[0]);
                window.draw(sprittest[1]);
                
		window.display();
	}
}
