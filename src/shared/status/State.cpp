#include "../status/State.h"
#include "../status.h"
#include <iostream>
#include <fstream>
using namespace status;
using namespace std;


State::State()
{

}

State::~State()
{
    delete lands;
    delete buildings;
    delete units;
}

void State::initialisation(std::string& file_name)
{
    this->text_file_name = file_name;
    setDimensions(text_file_name);
    string lands_s = "Lands";
    string buildings_s = "Buildings";
    string units_s = "Units";
    cout << "Setting lands..." << endl;
    lands = new ElementTab(text_file_name, this->width, this->height, lands_s);
    cout << "Setting buildings..." << endl;
    buildings = new ElementTab(text_file_name, this->width, this->height, buildings_s);
    cout << "Setting units..." << endl;
    units = new ElementTab(text_file_name, this->width, this->height, units_s);
    cout << "Done" << endl;
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

void State::setDimensions(string& text_file_name)
{
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

size_t State::getDay() const
{
    return day;
}

void State::setDay (size_t day)
{
    this->day = day;
}

int State::getHeight() const
{
	return this->height;
}

int State::getWidth() const
{
	return this->width;
}
