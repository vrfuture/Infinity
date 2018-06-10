#include "utils/Algorithm.h"
#include "engine/engine.h"

using Infinity::engine;

int main()
{
    // engine initialization
    Infinity::initEngine();

    // infinity main update and rendering loop
    engine.engine->mainloop();

    // close engine and return properly
    Infinity::shutdownEngine();
    return 0;
}