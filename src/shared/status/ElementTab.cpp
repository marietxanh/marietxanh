#include "../status/ElementTab.h"
#include <iostream>
using namespace status;
using namespace std;

ElementTab::ElementTab (int width, int height, TypeID type_id): width(width), height(height)
{
    /*utilisation de la fonction resize
     en remplacement d'une boucle for supplementaire*/
    array.resize(width);
    for(int i(0); i < width; i++)
        {
            array[i].resize(height);
        }
}

ElementTab::~ElementTab()
{
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
}

int ElementTab::getWidth() const
{
        return width;
}

int ElementTab::getHeight() const
{
        return height;
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
