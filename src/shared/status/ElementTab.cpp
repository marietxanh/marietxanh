#include "../status/ElementTab.h"
#include <iostream>
#include <fstream>

using namespace status;
using namespace std;

ElementTab::ElementTab (char* text_file_name, int width, int height, char* type_element): width(width), height(height)
{
    /*utilisation de la fonction resize
     en remplacement d'une boucle for supplementaire*/
    element_array.resize(height);
    layer_array.resize(height);
    for(int i(0); i < width; i++)
        {
            element_array[i].resize(width);
            layer_array[i].resize(width);
        }
    setLayer_array(text_file_name, type_element);
    setTextures_references(text_file_name, type_element);
    setElement_array();
}

ElementTab::~ElementTab()
{
    int height = element_array.size();
    int width = element_array[0].size();
    for(int i(0); i < height; i++)
    {
        for(int j(0); j < width; j++)
        {
            /*suppression des contenus des pointeurs
             et repointage sur l'adresse 0*/
            delete element_array[i][j];
            element_array[i][j] = 0;
        }
    }
}

Element* ElementTab::getElement(int i, int j)
{
        return array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
    if(array[i][j] == NULL) array[i][j] = element;
    else
    {
        printf("An element is already using this space.\n");
        delete element;
        element = 0;
    }
}

void ElementTab::setLayer_array(std::string& text_file_name, std::string& type_layer)
{
    std::cout << "Accessing text file " << text_file_name << std::endl;
    ifstream file_access(text_file_name);
    if(!file_access)
    {
        std::cout << "Cannot load " << text_file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    string line;

    if((string)(type_layer) == "Lands"){
        do{getline(file_access, line);}
        while(line != "type=Lands");
    }
    else if((string)(type_layer) == "Buildings"){
        do{getline(file_access, line);}
        while(line != "type=Buildings");
    }

    do{getline(file_access, line);}
    while(line != "data=");

    size_t temp, found;
    string::size_type sz;
    string digit_s;
    
    int width = layer_array[0].size();
    int height = layer_array.size();
    
    for(int i(0); i < height; i++)
    {
        getline(file_access, line);
        found = 0;
        temp = 0;
        for(int j(0); j < height; j++)
        {

            found = line.find(',', found + 1);
            if(found != string::npos)
            {
                digit_s = line.substr(temp, found - temp);

                layer_array[i][j] = stoi(digit_s, &sz);
                cout << layer_array[i][j] << " ";
                temp = found + 1;
            }
        }
        if(i < height - 1) cout << endl;
    }
    found = line.find('\n');
    digit_s = line.substr(temp, found - temp);
    layer_array[height - 1][width - 1] = stoi(digit_s, &sz);
    cout << layer_array[height - 1][width - 1] << endl;

    file_access.close();
    cout << text_file_name << " closed" << endl;
}

void ElementTab::setTextures_references(std::string& text_file_name, std::string& type_layer)
{
    std::cout << "Accessing text file " << text_file_name << std::endl;
    ifstream file_access(text_file_name);
    if(!file_access)
    {
        std::cout << "Cannot load " << text_file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    string line;
    
    do{ getline(file_access, line);
    }while(line != "[tilesets]");
    
    int k = 1;
    
    string image_name_s;
    do
    {
        size_t found = line.find('.');
        size_t temp = line.find('=') + 1;
        string::size_type sz;

        if(found != string::npos)
        {
            image_name_s = line.substr(temp, found - temp);
        }

        if((string)(type_layer) == "Lands"){
            found = image_name_s.find("lands");
            if(found != string::npos){
                image_name_s = "res/" + image_name_s + ".png";
                if(textures_references.size() == 0) textures_references.resize(k);
                else textures_references.push_back(image_name_s);
            }
        }

        else if((string)(type_layer) == "Buildings"){
            found = image_name_s.find("buildings");
            if(found != string::npos){
                image_name_s = "res/" + image_name_s + ".png";
                if(textures_references.size() == 0) textures_references.resize(k);
                else textures_references.push_back(image_name_s);
            }
        }
        k++;
        getline(file_access, line);
    }while(line != "\0");
    
    file_access.close();
}

void ElementTab::setElement_array(string& text_file_name, string& type_layer)
{
    int height = layer_array.size();
    int width = layer_array[0].size();
    size_t found;
    size_t temp;
    string stock;
    if(type_layer == "Lands"){
        for(int i(0); i < height; i++)
        {
            for(int j(0); j < width; j++)
            {
                if(layer_array[i][j] != 0){
                    found = 0;
                    temp = 0;
                    temp = textures_references[layer_array[i][j]].find('/') + 1;
                    found = textures_references[layer_array[i][j]].find('/', temp);
                    stock = textures_references[layer_array[i][j]].substr(found, found - temp);
                    if(stock == "forest") setElement(i, j, FOREST);
                    else if(stock == "mountain") setElement(i, j, new Land(MOUNTAIN));
                    else if(stock == "plain") setElement(i, j, new Land(PLAIN));
                    else if(stock == "beach") setElement(i, j, new Land(BEACH));
                    else if(stock == "river") setElement(i, j, new Land(RIVER));
                    else if(stock == "river_mouth") setElement(i, j, new Land(RIVER_MOUTH));
                    else if(stock == "shore") setElement(i, j, new Land(SHORE));
                    else if(stock == "reef") setElement(i, j, new Land(REEF));
                    else if(stock == "sea") setElement(i, j, new Land(SEA));
                    else if(stock == "crossroad") setElement(i, j, new Land(CROSSROAD));
                    else if(stock == "road") setElement(i, j, new Land(ROAD));
                    else if(stock == "bridge") setElement(i, j, new Land(BRIDGE));
                }
            }
        }
    }
    
    else if(type_layer == "Buildings")
    {
        string line = "/advance_wars_sprites_";
        for(int i(0); i < height; i++)
        {
            for(int j(0); j < width; j++)
            {
                if(layer_array[i][j] != 0)
                {
                    found = 0;
                    temp = 0;
                    for(int k (0); k < 2; k++)
                    {
                        temp = textures_references[layer_array[i][j]].find(line, temp) + 1;
                    }
                    found = textures_references[layer_array[i][j]].find('_', temp + line.size());
                    stock = textures_references[layer_array[i][j]].substr(temp + line.size(), found - (temp + line.size()));
                    if(stock == "city") setElement(i, j, new Building(TOWN));
                    else if(stock == "hq") setElement(i, j, new Building(HQ));
                    else if(stock == "factory") setElement(i, j, new Building(FACTORY));
                    else if(stock == "port") setElement(i, j, new Building(PORT));
                    else if(stock == "airport") setElement(i, j, new Building(AIRPORT));
                }
            }
        }
    }
    
}
