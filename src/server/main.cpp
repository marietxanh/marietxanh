#include <iostream>
#include "Record/Record.h"

int main(int argc, char **argv)
{
    if(argc == 2){
            if(std::string(argv[1]) == "record")
            {
                Record::recording();
            }
    }
}
