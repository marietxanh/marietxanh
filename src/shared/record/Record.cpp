/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Record.cpp
 * Author: pierre
 * 
 * Created on December 12, 2017, 10:26 AM
 */
#include "../../shared/status.h"
#include "../../shared/engine.h"
#include "../../shared/ai.h"
#include "Record.h"

using namespace engine;
using namespace render;
using namespace status;
using namespace ai;
using namespace sf;
using namespace std;

Record::Record() {
    
}


Record::~Record() {
}

void Record::recording(){
    string file_name = "res/test_ai.txt";
    Engine* moteur = new Engine();
    moteur->setEnableRecord(true);
    moteur->addCommand(new LoadMap(file_name));
    moteur->update();
    int height = moteur->getState()->getHeight();
    int width = moteur->getState()->getWidth();
    for(int i(0); i <  height; i++)
    {
            for(int j(0); j < width; j++)
            {
                    if(moteur->getState()->getBuildings()->getElement(i, j) != NULL)
                    {
                            if(((Building*)(moteur->getState()->getBuildings()->getElement(i, j)))->getType_building() == FACTORY)
                            {
                                    moteur->addCommand(new CreateUnit(INFANTRY, i, j));
                            }
                    }
            }
    }
    moteur->update();
    string move = "move";
    string attack = "attack";
    HeuristicAI art_int;
    for(int i(0); i < 20; i++)
    {
        cout << "--------------------------------------------" << endl;
        art_int.run(moteur);
        cout << "--------------------------------------------" << endl;
        art_int.addCommand(move);
        art_int.addCommand(attack);
        moteur->addCommand(new ResetUnits());
        moteur->update();
    }
    delete moteur;
}
