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
#include "render.h"
#include "../shared/engine.h"
#include "../shared/status.h"

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
        else if(std::string(argv[1]) == "render"){
            TestRender::testRender();
        }
        else if(std::string(argv[1]) == "engine"){
            TestEngine::testEngine();
        }
    }
    else
    {
        cout << "Commandes disponibles :\n" <<
                "hello : affiche un message de bienvenue\n" <<
                "state : instancie un etat du jeu\n" <<
                "render : affiche le rendu d'un etat du jeu\n" <<
                "engine : affiche une succession d'etats du jeu en passant des commandes\n" << endl;
    }
    return 0;
}