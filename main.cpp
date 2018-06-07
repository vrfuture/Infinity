#include "utils/Algorithm.h"
#include "engine/engine.h"

int main()
{
    // Infinity engine initialization
    Infinity::Engine engine;
    engine.init();

    // main loop
    engine.mainloop();

    // close engine and return properly
    engine.shutdown();
    return 0;
}