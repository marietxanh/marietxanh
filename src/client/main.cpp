#include <iostream>

#include "../client/render.h"
#include "../shared/status.h"
#include "../shared/engine.h"
#include "../shared/ai.h"
#include "test/test.h"
#include "SFML/Network.hpp"
#include "../shared/record.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

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
            TestThread().testThread(false);
        }
        else if(std::string(argv[1]) == "play"){
            TestThread().testThread(true);
        }
        
        else if(std::string(argv[1]) == "network"){
            sf::Http http ("http://localhost",8080);
            sf::Http::Request req0 ("version");
            sf::Http::Response rep = http.sendRequest(req0);
            std::cout<<rep.getBody()<<std::endl;
            std::srand(std::time(NULL));
            int val = rand();
            Json::Value obj;
            obj["name"] = std::to_string(val);
            obj["teamcolor"] = status::ORANGE;
            obj["free_player"] = true;
            sf::Http::Request req1 ("player", sf::Http::Request::Method::Put , obj.toStyledString());
            req1.setField("Content-Type","application/x-www-form-urlencoded");
            rep = http.sendRequest(req1);
            std::cout<< rep.getBody() << std::endl;
   
            int id = 0;
            Json::Reader jsonReader;
            Json::Value jsonIn;
            if (jsonReader.parse(rep.getBody(),jsonIn))
            id = jsonIn["id"].asInt();

            sf::Http::Request req2 ("player/" + std::to_string(id));
            rep = http.sendRequest(req2);
            std::cout << rep.getBody()<<std::endl;

            sf::Http::Request req3 ("player/-1");
            rep = http.sendRequest(req3);
            std::cout<<"number of players : " << rep.getBody() << std::endl;

            getc(stdin);

            sf::Http::Request req4 ("player/"+ std::to_string(id), sf::Http::Request::Method::Delete);
            rep = http.sendRequest(req4);

            sf::Http::Request req5 ("player/-1");
            rep = http.sendRequest(req5);
            std::cout<< "number of players : " << rep.getBody() << std::endl;
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
