#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "test/TestState.h"

using namespace std;
using namespace status;

int main(int argc,char* argv[]) 
{
    if(argc == 2){
        if(std::string(argv[1]) == "hello"){
            cout << "Hello everyone !" << endl;
            return 0;
        }
        else if(std::string(argv[1]) == "state"){
            TestState::testState();
        }
    }
    return 0;
}