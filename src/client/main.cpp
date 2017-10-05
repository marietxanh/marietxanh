#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "test/testState.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    Exemple exemple;
    exemple.setX(53);
    if(argc == 2){
        if(std::string(argv[1]) == "hello"){
            cout << "Bonjour tout le monde !" << endl;
            return 0;
        }
        else if(std::string(argv[1]) == "state"){
            int ret = testState();
            if (ret==0)
                cout << "état validé" << endl;
            else 
                cout <<"état non valide" << endl;
        }
    }
    return 0;
}
