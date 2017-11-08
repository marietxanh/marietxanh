/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "LoadCommand.h"


LoadCommand::LoadCommand (const char* f){
    
}

CommandTypeId const LoadCommand::getTypeId (){
    return CommandTypeId(LOAD);
}

void LoadCommand::execute (status::State& state){
    state.State(file_name);
    
}
    
// Setters and Getters
const std::string& LoadCommand::getFile_name() const{
    return this->file_name;
}

void LoadCommand::setFile_name(const std::string& f_name){
    this->file_name = f_name;
}
