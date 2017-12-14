/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Record.h
 * Author: pierre
 *
 * Created on December 12, 2017, 10:26 AM
 */

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <thread>
#include <mutex>
#include <time.h>
#include "../../client/render.h"
#include "../../shared/ai.h"
#include "../../shared/engine.h"
#include "../../shared/status.h"
#include "../../client/render/Display.h"

class Record {
public:
    Record();
    virtual ~Record();
    void recording();
    void run(engine::Engine* moteur);
    void replay();
private:
    static std::mutex mtx;
    bool running = true;

};

#endif /* RECORD_H */

