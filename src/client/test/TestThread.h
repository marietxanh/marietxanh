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
#include <string>
#include <thread>
#include <mutex>
#include "../render.h"
#include "../../shared/ai.h"
#include "../../shared/engine.h"
#include "../../shared/status.h"

class TestThread {
public:
    TestThread();
    TestThread(const TestThread& orig);
    virtual ~TestThread();
    static void testThread();
    void engine();
private:

};

#endif /* TESTTHREAD_H */

