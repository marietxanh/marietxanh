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
        
        Display display(state);
        while(display.getWindow().isOpen())
	{
		sf::Event event;
		while(display.checkEvent(event))
		{
			if(event.type == sf::Event::Closed)
				display.closeWindow();
		}
                
                display.refreshWindow();
	}
        delete state;
}