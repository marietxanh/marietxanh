#include <iostream>

#include "../server/Record/Record.h"
#include "../client/test/TestRender.h"
#include "../client/test/TestState.h"
#include "../client/test/TestEngine.h"
#include "../client/test/TestThread.h"
#include "../client/test/TestEngine.h"
#include "../client/render.h"
#include "../shared/engine.h"
#include "../shared/status.h"
#include "../shared/ai.h"

int main(int argc, char **argv)
{
    if(argc == 2){
            if(std::string(argv[1]) == "record")
            {
                Record().recording();
            }
    }
}
