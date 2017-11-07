#include "../status/State.h"
#include <iostream>
#include <fstream>
using namespace status;
using namespace std;


State::State(char* text_file_name) : text_file_name(text_file_name)
{
        setDimensions(text_file_name);
        lands = new ElementTab(text_file_name, this->width, this->height, "Lands");
        buildings = new ElementTab(text_file_name, this->width, this->height, "Buildings");
        units = new ElementTab(text_file_name, this->width, this->height, "Units");
}

State::~State()
{
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
{
    return units;
}

void State::setDimensions(char* text_file_name)
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
