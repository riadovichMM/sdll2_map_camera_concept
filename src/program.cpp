#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./header_files/main.hpp"

int main(int argv, char** args) {
    Main* main_obj = new Main();
    main_obj->init("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480);
    main_obj->game_loop();
    main_obj->clean();
    delete main_obj;

    return 0;
}


