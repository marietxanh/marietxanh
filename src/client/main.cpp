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
            TestRender::testRender("res/test_render.txt");
        }
        else if(std::string(argv[1]) == "engine"){
            cout<< "Appuyer sur la barre d'espace pour charger un nouvel état:\n"<< endl;
            cin >> answer;
            if(answer ==' ')
                TestEngine::testEngine();
            else cout<<"erreur : Vous n'avez pas appuyé sur la bonne touche\n"<< endl;
        }
    }
    return 0;
}