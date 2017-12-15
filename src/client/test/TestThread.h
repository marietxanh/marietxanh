/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestThread.h
 * Author: pierre
 *
 * Created on December 11, 2017, 2:07 PM
 */

#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <thread>
#include <mutex>
#include <time.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include "../render.h"
#include "../../shared/ai.h"
#include "../../shared/engine.h"
#include "../../shared/status.h"

class TestThread {
public:
    TestThread();
    TestThread(const TestThread& orig);
    virtual ~TestThread();
    void testThread(bool);
    
private:
    static std::mutex mtx;
    bool running = true;
    void run(engine::Engine* moteur);

};

#endif /* TESTTHREAD_H */

