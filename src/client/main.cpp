#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML




#include "../shared/status.h"
#include "../client/render.h"
#include "../shared/engine.h"
#include "../shared/ai.h"
#include "test/test.h"
#include "../server/Record/Record.h"
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
        else if(std::string(argv[1]) == "random_ai"){
            TestAI::testRandom();
        }
        else if(std::string(argv[1]) == "heuristic_ai"){
            TestAI::testHeuristic();
        }
        else if(std::string(argv[1]) == "deep_ai"){
            TestAI::testDeep();
        }
        else if(std::string(argv[1]) == "thread"){
            TestThread().testThread();
        }
        else if(std::string(argv[1]) == "play"){
            Record().replay();
        }
    }
    else
    {
        cout << "Commandes disponibles :\n" <<
                "hello : affiche un message de bienvenue\n" <<
                "state : instancie un etat du jeu\n" <<
                "render : affiche le rendu d'un etat du jeu\n" <<
                "engine : affiche une succession d'etats du jeu en passant des commandes\n" << 
                "random_ai : affiche une succession d'etats du jeu engendres par les commandes d'une AI\n" <<
                "heuristic_ai : affiche une IA dirigee par une fonction de recherche\n" <<
                "deep_ai : affiche un IA qui utilise l'algorithme minmax\n" <<
                "thread : affiche une succession d'etats du jeu traites par deux threads\n";
    }
    return 0;
}
