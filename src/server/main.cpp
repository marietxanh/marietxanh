#include <iostream>

#include "../client/render.h"
#include "../shared/status.h"
#include "../shared/engine.h"
#include "../shared/ai.h"
#include "../client/test/test.h"
#include "../shared/record/Record.h"


using namespace std;
using namespace status;

int main(int argc, char **argv)
{
    if(argc == 2){
            if(std::string(argv[1]) == "record")
            {
                Record().recording();
            }
    }
    return 0;
}
