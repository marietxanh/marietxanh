#include "../status/ElementTab.h"
#include <iostream>
using namespace status;
using namespace std;

ElementTab::ElementTab (char* text_file_name, int width, int height, char* type_element): width(width), height(height)
{
    /*utilisation de la fonction resize
     en remplacement d'une boucle for supplementaire*/
    element_array.resize(width);
    layer_array.resize(width);
    for(int i(0); i < width; i++)
        {
            element_array[i].resize(height);
            layer_array[i].resize(height);
        }
    setLayer_array(text_file_name, type_element);
}

ElementTab::~ElementTab()
{
    for(int i(0); i < element_array.size(); i++)
    {
        for(int j(0); j < element_array[i].size(); j++)
        {
            /*suppression des contenus des pointeurs
             et repointage sur l'adresse 0*/
            delete element_array[i][j];
            element_array[i][j] = 0;
        }
    }
    //cout << "Suppression du tableau terminée." << endl;
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
    
    int width = layer_array.size();
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
