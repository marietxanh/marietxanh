#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "test/TestState.h"
#include "test/TestRender.h"
<<<<<<< HEAD
=======
#include "test/TestEngine.h"
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42

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
<<<<<<< HEAD
            TestRender::testRender();
=======
            TestRender::testRender("res/test_render.txt");
        }
        else if(std::string(argv[1]) == "engine"){
            cout<< "Appuyer sur la barre d'espace pour charger un nouvel état:\n"<< endl;
            cin >> answer;
            if(answer ==' ')
                TestEngine::testEngine();
            else cout<<"erreur : Vous n'avez pas appuyé sur la bonne touche\n"<< endl;
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
        }
    }
    return 0;
}