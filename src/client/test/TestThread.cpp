/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestThread.cpp
 * Author: pierre
 * 
 * Created on December 11, 2017, 2:07 PM
 */

#include "TestThread.h"

using namespace engine;
using namespace render;
using namespace status;
using namespace ai;
using namespace sf;
using namespace std;

std::mutex TestThread::mtx;

TestThread::TestThread() {
}

TestThread::TestThread(const TestThread& orig) {
}

TestThread::~TestThread() {
}

void TestThread::testThread(bool replay)
{
    string file_name = "res/test_ai.txt";
    Engine* moteur = new Engine();
    moteur->setEnableReplay(replay);
    if (!moteur->getEnableReplay())
    {
        moteur->addCommand(new LoadMap(file_name));
        moteur->update();
    }
    std::thread vroum(&TestThread::run, this, moteur);
    
    Display display(moteur->getState());
    
    std::cout << "Window opens" << std::endl;
    while(display.getWindow().isOpen())
    {
        mtx.lock();
        sf::Event event;
        
        while(display.checkEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                display.closeWindow();
                this->running = false;
                cout << "Window close request" << endl;
            }
        }
        
        display.getUnits()->refresh_array();
        display.refreshWindow();
        mtx.unlock();
        
        sleep(1);
    }
        
    delete moteur;
    vroum.join();
    std::cout << "Window closed" << std::endl;
}

void TestThread::run(Engine* moteur){
    mtx.lock();
    if(moteur->getEnableReplay())
    {
        Json::Value in;
        std::ifstream file ("res/record.json");
        file >> in;
        file.close();
        
        for(Json::ArrayIndex i(0); i < in.size(); i++)
        {
            Command* command;
            string type = in[i]["type_command"].asString();
            if(type == "LoadMap") ((LoadMap*)(command))->deserialize(in[i]);
            else if(type == "AttackUnit") ((AttackUnit*)(command))->deserialize(in[i]);
            else if(type == "CaptureBuilding") ((CaptureBuilding*)(command))->deserialize(in[i]);
            else if(type == "CreateUnit") ((CreateUnit*)(command))->deserialize(in[i]);
            else if(type == "MoveUnit") ((MoveUnit*)(command))->deserialize(in[i]);
            else if(type == "ResetUnits") ((ResetUnits*)(command))->deserialize(in[i]);
        }
    }
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
    mtx.unlock();
    sleep(2);
    string move = "move";
    string attack = "attack";
    HeuristicAI art_int;
    while(running)
    {
        mtx.lock();
        cout << "--------------------------------------------" << endl;
        art_int.run(moteur);
        cout << "--------------------------------------------" << endl;
        art_int.addCommand(move);
        art_int.addCommand(attack);
        moteur->addCommand(new ResetUnits());
        moteur->update();
        
        mtx.unlock();
        sleep(2);
    }

}

