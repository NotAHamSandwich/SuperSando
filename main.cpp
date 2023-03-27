#include <iostream>
#include "engine/window.h"

int main() 
{
    using namespace engine;
    using namespace graphics;
    Window window("Helllo World", 960, 540);
    
        window.draw();
    
    

    SDL_Delay(2000);
}

