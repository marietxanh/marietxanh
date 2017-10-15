#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "status.h"

using namespace std;
using namespace status;

int main(int argc,char* argv[]) 
{

	if(argv[1]=="hello"){
    		cout << "Bonjour tout le monde !\n" << endl;
	}
    return 0;
}
