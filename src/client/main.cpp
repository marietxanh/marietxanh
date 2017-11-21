#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "test/TestState.h"
#include "test/TestRender.h"
#include "test/TestEngine.h"
#include "test/TestAI.h"
#include "render.h"
#include "../shared/engine.h"
#include "../shared/status.h"
#include "../shared/ai.h"

using namespace std;
using namespace status;

int main(int argc,char* argv[]) 
{
	//srand(time(NULL));
    if(argc == 2){
        if(std::string(argv[1]) == "hello"){
            cout << "Hello everyone !" << endl;
            return 0;
        }
        else if(std::string(argv[1]) == "state"){
            TestState::testState();
        }
        else if(std::string(argv[1]) == "render"){
            TestRender::testRender();
        }
        else if(std::string(argv[1]) == "engine"){
            TestEngine::testEngine();
        }
        else if(std::string(argv[1]) == "random_ai"){
            TestAI::testAI();
        }
    }
    else
    {
        cout << "Commandes disponibles :\n" <<
                "hello : affiche un message de bienvenue\n" <<
                "state : instancie un etat du jeu\n" <<
                "render : affiche le rendu d'un etat du jeu\n" <<
                "engine : affiche une succession d'etats du jeu en passant des commandes\n" << 
                "random_ai : affiche une succession d'etats du jeu engendres par les commandes d'une AI\n" << endl;
    }
    return 0;
}
