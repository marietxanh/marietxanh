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
        ElementTabLayer *units = new ElementTabLayer(state->getUnits());
        std::vector<std::string> references_text_units;
        references_text_units.push_back("res/advance_wars_sprites_units/advance_wars_sprites_units_orange/advance_wars_sprites_orange_infantry.png");
        units->getTextures_pack()->setTexturesArray(references_text_units);
        state->getUnits()->setElement(2, 1, new Unit(INFANTRY));
        units->getSprite(2, 1).setPosition(sf::Vector2f(1 * 16, 2 * 16));
	units->getSprite(2, 1).setTexture(units->getTextures_pack()->getText(0));
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
                            if(state->getUnits()->getElement(i, j) != NULL)
				window.draw(units->getSprite(i, j));
			}
                        
		}
                
		window.display();
	}
}