#include "TestRender.h"

using namespace sf;
using namespace render;
using namespace status;
using namespace std;

void TestRender::testRender()
{
	std::string text_file_name = "res/test_render.txt";
        /*creation des terrains et des batimentsx*/
	State* state = new State();
        state->initialisation(text_file_name);
        ElementTabLayer *lands = new ElementTabLayer(state->getLands());
        cout << "lands layer OK" << endl;
        ElementTabLayer *buildings = new ElementTabLayer(state->getBuildings());
        cout << "buildings layer OK" << endl;
        ElementTabLayer *units = new ElementTabLayer(state->getUnits());
        cout << "units layer OK" << endl;
        
        /*creation d'une couche contenant les unites
        std::vector<std::string> references_text_units;
        references_text_units.push_back("res/advance_wars_sprites_units/advance_wars_sprites_units_orange/advance_wars_sprites_orange_infantry.png");
        units->getTextures_pack()->setTexturesArray(references_text_units);
        state->getUnits()->setElement(2, 1, new Unit(INFANTRY, ORANGE));
        units->getSprite(2, 1).setPosition(sf::Vector2f(1 * 16, 2 * 16));
	units->getSprite(2, 1).setTexture(units->getTextures_pack()->getText(0));
        */
        /*creation fenetre en fonction des parametres du fichier charge*/
        sf::RenderWindow window(sf::VideoMode(state->getWidth() * 16, state->getHeight() * 16), "RenderWindow");
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
                
		for(int i(0); i < state->getHeight(); i++)
		{
			for(int j(0); j < state->getWidth(); j++)
			{
                            /*dessine dans l'ordre les differentes "couches"
                             d'abord les terrains, ensuite les batiments puis les unites*/
                            if(state->getLands()->getLayerArray(i, j) > 0)
				window.draw(lands->getSprite(i ,j));
                            if(state->getBuildings()->getLayerArray(i, j) > 0)
				window.draw(buildings->getSprite(i, j));
                            if(state->getUnits()->getElement(i, j) != NULL)
				window.draw(units->getSprite(i, j));
			}
                        
		}
                
		window.display();
	}
}