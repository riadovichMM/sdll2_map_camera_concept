#pragma once
#include "../../include/SDL2/SDL.h"
#include "./camera.hpp"
#include "./map.hpp"
#include "./player.hpp"

class Main {
    public:
        Camera* camera;


        Main();
        ~Main();

        void init(const char* title, int x_pos, int y_pos, int screen_width, int screen_height);
        void handle_event();
        void update();
        void render();
        void game_loop();
        void clean();

    private:
        SDL_Window* ptr_window;
        SDL_Renderer* ptr_renderer;
        bool run_loop;
        int frame_count;
        Map* map;
        int screen_width;
        int screen_height;
        Player* player;
};

