#include "../status/State.h"
<<<<<<< HEAD
#include "../status.h"
#include <iostream>
#include <fstream>
=======
#include <iostream>
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
using namespace status;
using namespace std;


State::State(string& text_file_name) : text_file_name(text_file_name)
{
<<<<<<< HEAD
        setDimensions(text_file_name);
        string lands_s = "Lands";
        string buildings_s = "Buildings";
        lands = new ElementTab(text_file_name, this->width, this->height, lands_s);
        buildings = new ElementTab(text_file_name, this->width, this->height, buildings_s);
=======
        grid = new ElementTab(width, height, LAND);
        units = new ElementTab(width, height, UNIT);
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
}

State::~State()
{
<<<<<<< HEAD
    delete lands;
    delete buildings;
    delete units;
    //cout << "Suppression des tableaux d'unités et terrains terminée." << endl;
}

ElementTab* State::getLands() const
{
        return lands;
}

ElementTab* State::getBuildings() const
{
        return buildings;
}

ElementTab* State::getUnits() const
=======
    delete grid;
    delete units;
    //cout << "Suppression des tableaux d'unités et terrains terminée." << endl;
}

ElementTab* State::getGrid()
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
{
    return units;
}

<<<<<<< HEAD
void State::setDimensions(string& text_file_name)
=======
ElementTab* State::getCharacters()
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
{
    std::cout << "Accessing text file " << text_file_name << std::endl;
    ifstream file_access(text_file_name);
    if(!file_access)
    {
        std::cout << "Cannot load " << text_file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    string line;
    int k = 0;
    getline(file_access, line);
    string width_s, height_s, tile_width_s, tile_height_s;
    do
    {
        switch(k)
        {
                case 1:
                        width_s = line.substr(6);
                        width = stoi(width_s);
                        break;
                case 2:
                        height_s = line.substr(7);
                        height = stoi(height_s);
                        break;
                case 3:
                        tile_width_s = line.substr(10);
                        tile_width = stoi(tile_width_s);
                        break;
                case 4:
                        tile_height_s = line.substr(11);
                        tile_height = stoi(tile_height_s);
                        break;
        }
        k++;
        getline(file_access, line);
    }while(line != "[tilesets]");
    
    file_access.close();
}
