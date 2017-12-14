#include <iostream>

#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

#include "../shared/status.h"
#include "../client/render.h"
#include "../shared/engine.h"
#include "../shared/ai.h"
#include "Record/Record.h"
#include "../client/test/test.h"

using namespace std;
using namespace status;

int main(int argc, char **argv)
{
    if(argc == 2){
            if(std::string(argv[1]) == "record")
            {
                Record().recording();
            }
    }
}
