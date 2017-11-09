/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestRender.h
 * Author: Pierre MARIET - Joanna XANH
 *
 * Created on 28 octobre 2017, 15:33
 */

#ifndef TESTRENDER_H
#define TESTRENDER_H

#include "../shared/status.h"
#include "render.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <unistd.h>

#define FRAMERATE 60
#define PERIOD (1 / FRAMERATE)
#include "../render.h"
#include <SFML/Window.hpp>
#include <iostream>

class TestRender
{
public:
    static void testRender();
    static void testRender(std::string file_name);
};


#endif /* TESTRENDER_H */

