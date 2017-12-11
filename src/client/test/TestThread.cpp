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
using namespace std;

TestThread::TestThread() {
}

TestThread::TestThread(const TestThread& orig) {
}

TestThread::~TestThread() {
}

void TestThread::testThread()
{
    std::thread engine(engine);
}

void TestThread::engine(){
    string file_name = "res/test_ai.txt";
    Engine* moteur = new Engine();
    moteur->addCommand(new LoadMap(file_name));
    moteur->update();
}

