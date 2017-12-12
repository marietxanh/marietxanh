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

class Record {
public:
    Record();
    Record(const Record& orig);
    virtual ~Record();
    static void recording();
private:

};

#endif /* RECORD_H */

