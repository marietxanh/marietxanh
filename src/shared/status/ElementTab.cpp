#include "../status/ElementTab.h"
#include "../status.h"
#include <iostream>
#include <fstream>

using namespace status;
using namespace std;

ElementTab::ElementTab (string& text_file_name, int width, int height, string& type_element)
{
    /*utilisation de la fonction resize
     en remplacement d'une boucle for supplementaire*/
<<<<<<< HEAD
    element_array.resize(height);
    layer_array.resize(height);
=======
    array.resize(width);
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    for(int i(0); i < width; i++)
        {
            element_array[i].resize(width);
            layer_array[i].resize(width);
        }
    setLayer_array(text_file_name, type_element);
    setTextures_references(text_file_name, type_element);
    setElement_array(type_element);
}

ElementTab::~ElementTab()
{
<<<<<<< HEAD
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
=======
    for(int i(0); i < width; i++)
    {
        for(int j(0); j < height; j++)
        {
            /*suppression des contenus des pointeurs
             et repointage sur l'adresse 0*/
            delete array[i][j];
            array[i][j] = 0;
        }
    }
    //cout << "Suppression du tableau terminée." << endl;
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
}

Element* ElementTab::getElement(int i, int j)
{
        return element_array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
    if(element_array[i][j] == NULL) element_array[i][j] = element;
    else
    {
        printf("An element is already using this space.\n");
        delete element;
        element = 0;
    }
}

<<<<<<< HEAD
void ElementTab::setLayer_array(std::string& text_file_name, std::string& type_layer)
=======
Element* ElementTab::getElement(int i, int j)
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

<<<<<<< HEAD
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
                textures_references.resize(k);
                textures_references[k - 1] = image_name_s;
            }
        }

        else if((string)(type_layer) == "Buildings"){
            found = image_name_s.find("buildings");
            if(found != string::npos){
                image_name_s = "res/" + image_name_s + ".png";
                textures_references.resize(k);
                textures_references[k - 1] = image_name_s;
            }
        }
        k++;
        getline(file_access, line);
    }while(line != "\0");
    
    file_access.close();
    cout << text_file_name << " closed" << endl;
}

void ElementTab::setElement_array(string& type_layer)
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
                if(layer_array[i][j] > 0){
                    found = 0;
                    temp = 0;
                    for(int k(0); k < 2; k++)
                    {
                        found = textures_references[layer_array[i][j]].find('/', found + 1);
                        temp = found + 1;
                    }
                    found = textures_references[layer_array[i][j]].find('/', found + 1);
                    stock = textures_references[layer_array[i][j]].substr(temp, found - temp);
                    if(stock == "forest") setElement(i, j, new Land(FOREST));
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
        for(int i(0); i < height; i++)
        {
            for(int j(0); j < width; j++)
            {
                if(layer_array[i][j] > 0)
                {
                    found = 0;
                    temp = 0;
                    for(int k(0); k < 3; k++)
                    {
                        found = textures_references[layer_array[i][j]].find('/', found + 1);
                        temp = found + 1;
                    }
                    found = textures_references[layer_array[i][j]].find('/', found + 1);
                    stock = textures_references[layer_array[i][j]].substr(temp, found - temp);
                    cout << stock << endl;
                    for(int k(0); k < 3; k++)
                    {
                        found = stock.find('_', found + 1);
                        temp = found + 1;
                    }
                    found = stock.find('_', found + 1);
                    stock = stock.substr(temp, found - temp);
                    cout << stock << "\n" << endl;
                    if(stock == "city") setElement(i, j, new Building(TOWN));
                    else if(stock == "hq") setElement(i, j, new Building(HQ));
                    else if(stock == "factory") setElement(i, j, new Building(FACTORY));
                    else if(stock == "port") setElement(i, j, new Building(PORT));
                    else if(stock == "airport") setElement(i, j, new Building(AIRPORT));
                }
            }
        }
    }
    
=======
void ElementTab::setElement(int i, int j, Element* element)
{
    if(array[i][j] == NULL) array[i][j] = element;
    else
    {
        printf("An element is already using this space.\n");
        delete element;
        element = 0;
    }
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
}
