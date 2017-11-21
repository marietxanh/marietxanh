#include "TestRender.h"

using namespace sf;
using namespace render;
using namespace status;
using namespace std;

void TestRender::testRender()
{
	std::string text_file_name = "res/test_render.txt";
        /*on cree deux plans
         les terrains qui ne seront jamais modifies
         les batiments qui peuvent changer de couleur
         en fonction de qui les possede
         ceci est dans l'objectif de modifier plus facilement
         la texture d'un sprite*/
	State* state = new State();
        state->initialisation(text_file_name);
        ElementTabLayer *lands = new ElementTabLayer(state->getLands());
        ElementTabLayer *buildings = new ElementTabLayer(state->getBuildings());
        sf::Texture texttest[2];
        sf::Sprite sprittest[2];
        
        /*creation de deux sprites directement ici pour tests affichages*/
        texttest[0].loadFromFile("res/advance_wars_sprites_lands/plain/plain.png");
        texttest[1].loadFromFile("res/advance_wars_sprites_lands/mountain/small_mountain.png");
        sprittest[0].setPosition(sf::Vector2f(0, 0));
        sprittest[1].setPosition(sf::Vector2f(16, 0));
        sprittest[0].setTexture(texttest[0]);
        sprittest[1].setTexture(texttest[1]);
	sf::RenderWindow window(sf::VideoMode(state->getWidth() * 16, state->getHeight() * 16), "RenderWindow");
        window.setFramerateLimit(30);
        //std::cout << state->getHeight() << " " << state->getWidth() << std::endl;
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
                
		for(int i(0); i < state->getHeight(); i++)
		{
			for(int j(0); j < state->getWidth(); j++)
			{
                            /*on dessine dans l'ordre les differents "calques"
                             d'abord les terrains et ensuite les batiments*/
                            if(state->getLands()->getLayerArray(i, j) > 0) {
                                //sf::Sprite sprite = lands->getSprite(i ,j);
                                //sprite.setTexture(texttest[0]);
                                //sprite.setPosition(sf::Vector2f(32, 32));
				window.draw((const sf::Sprite&)lands->getSprite(i ,j));
                            }
                            if(state->getBuildings()->getLayerArray(i, j) > 0)
				window.draw(buildings->getSprite(i, j));
			}
                        
		}
                
		window.display();
	}
}