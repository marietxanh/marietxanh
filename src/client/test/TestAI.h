/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestAI.h
 * Author: joanna
 *
 * Created on 16 novembre 2017, 16:27
 */

#ifndef TESTAI_H
#define TESTAI_H

#include <iostream>
#include <unistd.h>
#include "../../shared/ai.h"
#include "../../shared/engine.h"
#include "../../shared/status.h"
#include "../client/render.h"
#include <SFML/Window.hpp>

class TestAI
{
public:
    static void testRandom();
    static void testHeuristic();
    static void testDeep();
};


#endif /* TESTAI_H */
